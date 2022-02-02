/* Main code for Kaily 
 * 
 * Last Change: 2021.6.12 Yoon
 *   add Comment and arrange
 */

package application;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.BufferedReader;
import java.io.File;
import java.awt.GridLayout;
import java.awt.Image;
import java.io.IOException;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Calendar;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.ArrayList;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextPane;
import javax.swing.border.Border;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import javax.swing.text.html.HTMLDocument;
import javax.swing.text.html.HTMLEditorKit;

public class Main {
	public static JFrame frame;
	public static JButton UpdatePlanbtn;

	// Mood Calendar
	static Calendar date = Calendar.getInstance();
	static int yearMood = date.get(Calendar.YEAR);
	static int monthMood = date.get(Calendar.MONTH) + 1;
	static int dayMood = date.get(Calendar.DATE);
	static JLabel clock_time;

	/* Create the application. */
	public Main() {
		initialize();
	}

	// Determining the Tag text background color for each Plan
	public static String determineTagColor(String tag) {

		if (tag.equals(" Appointment ")) {
			return String.format("%s", "#CEF6D8");
		} else if (tag.equals(" School ")) {
			return String.format("%s", "#CEECF5");
		} else if (tag.equals(" Meal ")) {
			return String.format("%s", "#F6E3CE");
		} else if (tag.equals(" ETC ")) {
			return String.format("%s", "#E6E0F8");
		} else if (tag.equals(" Exam ")) {
			return String.format("%s", "#F6CECE");
		}
		return tag;
	}

	// Main Code
	public static void initialize() {
		Audio audio = new Audio("schedule-initial");

		/* ---------------- Frame ---------------------------- */
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		frame.setTitle("Knu Daily, Kaily");

		/* ---------------- Panel ---------------------------- */
		// Make Panel
		ImagePanel startPanel = new ImagePanel(new ImageIcon("./data/images/panel_page/Kaily_start.png").getImage());
		ImagePanel menuPanel = new ImagePanel(new ImageIcon("./data/images/panel_page/Kaily_menu.png").getImage());
		ImagePanel MoodPanel = new ImagePanel(new ImageIcon("./data/images/panel_page/MoodPanel.png").getImage());
		ImagePanel TrackerPanel = new ImagePanel(
				new ImageIcon("./data/images/panel_page/TrackerPanel_r.png").getImage());
		ImagePanel monthlyTrackerPanel = new ImagePanel(
				new ImageIcon("./data/images/panel_page/Tracker_monthly_panel.png").getImage());
		ImagePanel dailyTrackerPanel = new ImagePanel(
				new ImageIcon("./data/images/panel_page/Tracker_daily_panel.png").getImage());
		ImagePanel PlanPanel = new ImagePanel(new ImageIcon("./data/images/panel_page/PlanPanel.png").getImage());
		JTextPane PlanPrintPanel = new JTextPane();
		JScrollPane ScrollPrint = new JScrollPane(PlanPrintPanel) {
			public void setBorder(Border border) {

			}
		};

		// Make Mood Panel
		ImagePanel MoodMonth01 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/31_Panel.png").getImage());
		ImagePanel MoodMonth02 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/28_Panel.png").getImage());
		ImagePanel MoodMonth03 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/31_Panel.png").getImage());
		ImagePanel MoodMonth04 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/30_Panel.png").getImage());
		ImagePanel MoodMonth05 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/31_Panel.png").getImage());
		ImagePanel MoodMonth06 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/30_Panel.png").getImage());
		ImagePanel MoodMonth07 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/31_Panel.png").getImage());
		ImagePanel MoodMonth08 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/31_Panel.png").getImage());
		ImagePanel MoodMonth09 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/30_Panel.png").getImage());
		ImagePanel MoodMonth10 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/31_Panel.png").getImage());
		ImagePanel MoodMonth11 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/30_Panel.png").getImage());
		ImagePanel MoodMonth12 = new ImagePanel(
				new ImageIcon("./data/images/panel_page/MonthPanel/31_Panel.png").getImage());

		// Set Panel
		MoodPanel.setVisible(false);
		PlanPanel.setVisible(false);
		menuPanel.setVisible(false);

		PlanPanel.setLayout(null);

		PlanPrintPanel.setContentType("text/html");
		PlanPrintPanel.setEditable(false);

		frame.getContentPane().add(menuPanel);
		frame.getContentPane().add(PlanPanel);
		frame.getContentPane().add(MoodPanel);
		frame.getContentPane().add(startPanel);

		frame.setSize(startPanel.getDim());
		frame.setPreferredSize(startPanel.getDim());

		ScrollPrint.setBounds(154, 116, 807, 478);
		PlanPrintPanel.setEditable(false);
		PlanPrintPanel.setBounds(336, 90, 790, 509);
		PlanPanel.add(ScrollPrint, BorderLayout.CENTER);

		StyledDocument doc = PlanPrintPanel.getStyledDocument();

		/* ---------------- Icon ---------------------------- */
		ImageIcon clickTracker = new ImageIcon("./data/images/Icon/Tracker_click_line.png");
		ImageIcon clickPlan = new ImageIcon("./data/images/Icon/Plan_click_line.png");
		ImageIcon clickMood = new ImageIcon("./data/images/Icon/Mood_click_line.png");
		ImageIcon PlayIcon = new ImageIcon("./data/images/Icon/play.png");
		ImageIcon PauseIcon = new ImageIcon("./data/images/Icon/Pause.png");

		/* ---------------- Label ---------------------------- */

		// Clock Label
		clock_time = new JLabel("");
		clock_time.setForeground(new Color(153, 0, 51));
		clock_time.setFont(new Font("Digital-7 Italic", Font.PLAIN, 70));
		clock_time.setBounds(1045, 597, 190, 78);
		PlanPanel.add(clock_time);

		TimerThread th = new TimerThread(clock_time);
		ExecutorService executorService = Executors.newCachedThreadPool();
		executorService.execute(th);
		executorService.shutdown();

		/* ---------------- Button ---------------------------- */
		// Make the Button
		JButton plangoToMenubtn = new JButton("");
		JButton AddPlanbtn = new JButton("");
		JButton moodgoToMenubtn = new JButton("");
		UpdatePlanbtn = new JButton("");
		JButton Deletebtn = new JButton("");
		JButton Playbtn = new JButton("");
		JButton goToMenu = new JButton("당신의 하루를 함께하는 비서, Kaily");
		JButton Planbtn = new JButton("");
		JButton Moodbtn = new JButton("");
		JButton MonthBtn[][] = new JButton[12][];

		// Set the Icon
		AddPlanbtn.setIcon(new ImageIcon("./data/images/Icon/Add.png"));
		Deletebtn.setIcon(new ImageIcon("./data/images/Icon/delete.png"));
		UpdatePlanbtn.setIcon(new ImageIcon("./data/images/Icon/Update.png"));
		Planbtn.setIcon(new ImageIcon("./data/images/Icon/Plan_r.png"));
		Moodbtn.setIcon(new ImageIcon("./data/images/Icon/Mood_r.png"));

		// Plan Button
		Planbtn.setBorderPainted(false);
		Planbtn.setBackground(Color.WHITE);
		Planbtn.setBounds(322, 324, 90, 55);
		Planbtn.setRolloverIcon(clickPlan);
		menuPanel.add(Planbtn);
		Planbtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				menuPanel.setVisible(false);
				PlanPanel.setVisible(true);
			}
		});

		// Mood Button
		Moodbtn.setBorderPainted(false);
		Moodbtn.setBackground(Color.WHITE);
		Moodbtn.setBounds(851, 324, 120, 51);
		Moodbtn.setRolloverIcon(clickMood);
		menuPanel.add(Moodbtn);
		Moodbtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				menuPanel.setVisible(false);
				MoodPanel.setVisible(true);

				switch (monthMood) {
				case 1:
					MoodMonth01.setVisible(true);
					break;
				case 2:
					MoodMonth02.setVisible(true);
					break;
				case 3:
					MoodMonth03.setVisible(true);
					break;
				case 4:
					MoodMonth04.setVisible(true);
					break;
				case 5:
					MoodMonth05.setVisible(true);
					break;
				case 6:
					MoodMonth06.setVisible(true);
					break;
				case 7:
					MoodMonth07.setVisible(true);
					break;
				case 8:
					MoodMonth08.setVisible(true);
					break;
				case 9:
					MoodMonth09.setVisible(true);
					break;
				case 10:
					MoodMonth10.setVisible(true);
					break;
				case 11:
					MoodMonth11.setVisible(true);
					break;
				case 12:
					MoodMonth12.setVisible(true);
					break;
				}
			}
		});

		// Plan -> Menu Button
		plangoToMenubtn.setBounds(1215, 25, 48, 46);
		plangoToMenubtn.setBorderPainted(false);
		plangoToMenubtn.setContentAreaFilled(false);
		PlanPanel.add(plangoToMenubtn);

		plangoToMenubtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				PlanPanel.setVisible(false);
				menuPanel.setVisible(true);
			}
		});

		// Add Plan Button
		AddPlanbtn.setBounds(40, 635, 61, 56);
		AddPlanbtn.setBorderPainted(false);
		PlanPanel.add(AddPlanbtn);

		AddPlanbtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				new MakeAddPlanFrame();
			}
		});

		// Update Plan Button
		UpdatePlanbtn.setBounds(110, 635, 66, 56);
		PlanPanel.add(UpdatePlanbtn);
		UpdatePlanbtn.setBorderPainted(false);

		// Delete Plan Button
		Deletebtn.setBounds(181, 633, 61, 63);
		Deletebtn.setBorderPainted(false);
		Deletebtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				new DeletePlan();
			}
		});
		PlanPanel.add(Deletebtn);

		// Audio Play Button
		Playbtn.setIcon(PlayIcon);
		Playbtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {

				if (audio.isPlay == true) {
					audio.stop();
					Playbtn.setIcon(PlayIcon);
				} else {
					Playbtn.setIcon(PauseIcon);
					audio.play();
				}
			}
		});
		Playbtn.setBounds(253, 635, 61, 63);
		PlanPanel.add(Playbtn);
		Playbtn.setBorderPainted(false);

		// Update Plan Button
		UpdatePlanbtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String text = "";
				PlanPrintPanel.setText("");
				try {
					DB.updateDayDB();
				} catch (IOException e2) {
					System.out.println(e2);
				}

				try {

					HTMLEditorKit kit = new HTMLEditorKit();
					HTMLDocument HtmlDoc = new HTMLDocument();

					PlanPrintPanel.setEditorKit(kit);
					PlanPrintPanel.setDocument(HtmlDoc);
					
					for (Day d : DB.dayDB) {
						text += DB.searchScheduleList(d);
						kit.insertHTML(HtmlDoc, HtmlDoc.getLength(),
								"<p style='font-family: 나눔손글씨 가람연꽃; font-size: 25px; color: #323C73; font-weight: bold; font-style: italic;'>"
										+ d + "</p>",
								0, 0, null);
						kit.insertHTML(HtmlDoc, HtmlDoc.getLength(), "<p><hr align='left' width ='200px'></p>", 0, 0,
								null);
						for (Schedule s : DB.searchScheduleList(d).scheduleList) {
							String tag = String.format(" %s ", s.getTag());
							String output = String.format("     %02d : %02d ~ %02d : %02d %s", s.getStartHour(),
									s.getStartMin(), s.getFinishHour(), s.getFinishMin(), s.getContent());
							kit.insertHTML(HtmlDoc, HtmlDoc.getLength(), "<font size='6px'> <br> </font>", 0, 0, null);
							kit.insertHTML(HtmlDoc, HtmlDoc.getLength(),
									"<span style='font-family: 나눔손글씨 가람연꽃; font-size: 20px; color: black;'> <span style='background-color:"
											+ determineTagColor(tag) + ";'> &nbsp" + tag
											+ "&nbsp</span>&nbsp&nbsp&nbsp " + output + "</span>",
									0, 0, null);
						}
						kit.insertHTML(HtmlDoc, HtmlDoc.getLength(), "<font size='20px'><br><br><br></font>", 0, 0,
								null);
						Util.makeMp3(text, "schedule");
						audio.change("schedule");

					}
				} catch (Exception e1) {
					System.out.println(e1);
				}
			}
		});

		/* ---------------- Mood Panel ---------------------------- */

		MoodMonth01.setLayout(new GridLayout(5, 7));
		MoodMonth01.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth01);
		MoodMonth01.setVisible(false);
		MonthBtn[0] = new JButton[31];

		for (int i = 0; i < MonthBtn[0].length; i++) {
			MonthBtn[0][i] = new JButton();
			MonthBtn[0][i].setBorderPainted(false);
			MonthBtn[0][i].setContentAreaFilled(false);
			MoodMonth01.add(MonthBtn[0][i]);
			if (i <= 8) {
				if ((1 < monthMood) || (1 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[0][i].addActionListener(new MyActionListener("010" + Integer.toString(i + 1)));
				}
			} else {
				if ((1 < monthMood) || (1 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[0][i].addActionListener(new MyActionListener("01" + Integer.toString(i + 1)));
				}
			}
		}

		// Month : 2 (Panel)

		MoodMonth02.setLayout(new GridLayout(5, 7));
		MoodMonth02.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth02);
		MoodMonth02.setVisible(false);
		MonthBtn[1] = new JButton[31];

		for (int i = 0; i < MonthBtn[1].length; i++) {
			MonthBtn[1][i] = new JButton();
			MonthBtn[1][i].setBorderPainted(false);
			MonthBtn[1][i].setContentAreaFilled(false);
			MoodMonth02.add(MonthBtn[1][i]);
			if (i < 28) {
				if (i <= 8) {
					if ((2 < monthMood) || (2 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[1][i].addActionListener(new MyActionListener("020" + Integer.toString(i + 1)));
					}
				} else {
					if ((2 < monthMood) || (2 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[1][i].addActionListener(new MyActionListener("02" + Integer.toString(i + 1)));
					}
				}
			} else {
				MonthBtn[1][i].setEnabled(false);
			}

		}

		// Month : 3 (Panel)
		MoodMonth03.setLayout(new GridLayout(5, 7));
		MoodMonth03.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth03);
		MoodMonth03.setVisible(false);
		MonthBtn[2] = new JButton[31];

		for (int i = 0; i < MonthBtn[2].length; i++) {
			MonthBtn[2][i] = new JButton();
			MonthBtn[2][i].setBorderPainted(false);
			MonthBtn[2][i].setContentAreaFilled(false);
			MoodMonth03.add(MonthBtn[2][i]);
			if (i <= 8) {
				if ((3 < monthMood) || (3 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[2][i].addActionListener(new MyActionListener("030" + Integer.toString(i + 1)));
				}
			} else {
				if ((3 < monthMood) || (3 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[2][i].addActionListener(new MyActionListener("03" + Integer.toString(i + 1)));
				}
			}
		}

		// Month : 4 (Panel)
		MoodMonth04.setLayout(new GridLayout(5, 7));
		MoodMonth04.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth04);
		MoodMonth04.setVisible(false);
		MonthBtn[3] = new JButton[31];

		for (int i = 0; i < MonthBtn[3].length; i++) {
			MonthBtn[3][i] = new JButton();
			MonthBtn[3][i].setBorderPainted(false);
			MonthBtn[3][i].setContentAreaFilled(false);
			MoodMonth04.add(MonthBtn[3][i]);
			if (i < 30) {
				if (i <= 8) {
					if ((4 < monthMood) || (4 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[3][i].addActionListener(new MyActionListener("040" + Integer.toString(i + 1)));
					}
				} else {
					if ((4 < monthMood) || (4 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[3][i].addActionListener(new MyActionListener("04" + Integer.toString(i + 1)));
					}
				}
			} else {
				MonthBtn[3][i].setEnabled(false);
			}

		}

		// Month : 5 (Panel)
		MoodMonth05.setLayout(new GridLayout(5, 7));
		MoodMonth05.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth05);
		MoodMonth05.setVisible(false);
		MonthBtn[4] = new JButton[31];

		for (int i = 0; i < MonthBtn[4].length; i++) {
			MonthBtn[4][i] = new JButton();
			MonthBtn[4][i].setBorderPainted(false);
			MonthBtn[4][i].setContentAreaFilled(false);
			MoodMonth05.add(MonthBtn[4][i]);
			if (i <= 8) {
				if ((5 < monthMood) || (5 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[4][i].addActionListener(new MyActionListener("050" + Integer.toString(i + 1)));
				}
			} else {
				if ((5 < monthMood) || (5 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[4][i].addActionListener(new MyActionListener("05" + Integer.toString(i + 1)));
				}
			}
		}

		// Month : 6 (Panel)
		MoodMonth06.setLayout(new GridLayout(5, 7));
		MoodMonth06.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth06);
		MoodMonth06.setVisible(false);
		MonthBtn[5] = new JButton[31];

		for (int i = 0; i < MonthBtn[5].length; i++) {
			MonthBtn[5][i] = new JButton();
			MonthBtn[5][i].setBorderPainted(false);
			MonthBtn[5][i].setContentAreaFilled(false);
			MoodMonth06.add(MonthBtn[5][i]);
			if (i < 30) {
				if (i <= 8) {
					if ((6 < monthMood) || (6 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[5][i].addActionListener(new MyActionListener("060" + Integer.toString(i + 1)));
					}
				} else {
					if ((6 < monthMood) || (6 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[5][i].addActionListener(new MyActionListener("06" + Integer.toString(i + 1)));
					}
				}
			} else {
				MonthBtn[1][i].setEnabled(false);
			}
		}

		// Month : 7 (Panel)

		MoodMonth07.setLayout(new GridLayout(5, 7));
		MoodMonth07.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth07);
		MoodMonth07.setVisible(false);
		MonthBtn[6] = new JButton[31];

		for (int i = 0; i < MonthBtn[6].length; i++) {
			MonthBtn[6][i] = new JButton();
			MonthBtn[6][i].setBorderPainted(false);
			MonthBtn[6][i].setContentAreaFilled(false);
			MoodMonth07.add(MonthBtn[6][i]);
			if (i <= 8) {
				if ((7 < monthMood) || (7 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[6][i].addActionListener(new MyActionListener("070" + Integer.toString(i + 1)));
				}
			} else {
				if ((7 < monthMood) || (7 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[6][i].addActionListener(new MyActionListener("07" + Integer.toString(i + 1)));
				}
			}
		}

		// Month : 8 (Panel)
		MoodMonth08.setLayout(new GridLayout(5, 7));
		MoodMonth08.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth08);
		MoodMonth08.setVisible(false);
		MonthBtn[7] = new JButton[31];

		for (int i = 0; i < MonthBtn[7].length; i++) {
			MonthBtn[7][i] = new JButton();
			MonthBtn[7][i].setBorderPainted(false);
			MonthBtn[7][i].setContentAreaFilled(false);
			MoodMonth08.add(MonthBtn[7][i]);
			if (i <= 8) {
				if ((8 < monthMood) || (8 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[7][i].addActionListener(new MyActionListener("080" + Integer.toString(i + 1)));
				}
			} else {
				if ((8 < monthMood) || (8 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[7][i].addActionListener(new MyActionListener("08" + Integer.toString(i + 1)));
				}
			}
		}

		// Month : 9 (Panel)
		MoodMonth09.setLayout(new GridLayout(5, 7));
		MoodMonth09.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth09);
		MoodMonth09.setVisible(false);
		MonthBtn[8] = new JButton[31];

		for (int i = 0; i < MonthBtn[8].length; i++) {
			MonthBtn[8][i] = new JButton();
			MonthBtn[8][i].setBorderPainted(false);
			MonthBtn[8][i].setContentAreaFilled(false);
			MoodMonth09.add(MonthBtn[8][i]);
			if (i < 30) {
				if (i <= 8) {
					if ((9 < monthMood) || (9 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[8][i].addActionListener(new MyActionListener("090" + Integer.toString(i + 1)));
					}
				} else {
					if ((9 < monthMood) || (9 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[8][i].addActionListener(new MyActionListener("09" + Integer.toString(i + 1)));
					}
				}
			} else {
				MonthBtn[1][i].setEnabled(false);
			}
		}

		// Month : 10 (Panel)
		MoodMonth10.setLayout(new GridLayout(5, 7));
		MoodMonth10.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth10);
		MoodMonth10.setVisible(false);
		MonthBtn[9] = new JButton[31];

		for (int i = 0; i < MonthBtn[9].length; i++) {
			MonthBtn[9][i] = new JButton();
			MonthBtn[9][i].setBorderPainted(false);
			MonthBtn[9][i].setContentAreaFilled(false);
			MoodMonth10.add(MonthBtn[9][i]);
			if (i <= 8) {
				if ((10 < monthMood) || (10 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[9][i].addActionListener(new MyActionListener("100" + Integer.toString(i + 1)));
				}
			} else {
				if ((10 < monthMood) || (10 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[9][i].addActionListener(new MyActionListener("10" + Integer.toString(i + 1)));
				}
			}
		}

		// Month : 11 (Panel)
		MoodMonth11.setLayout(new GridLayout(5, 7));
		MoodMonth11.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth11);
		MoodMonth11.setVisible(false);
		MonthBtn[10] = new JButton[31];

		for (int i = 0; i < MonthBtn[10].length; i++) {
			MonthBtn[10][i] = new JButton();
			MonthBtn[10][i].setBorderPainted(false);
			MonthBtn[10][i].setContentAreaFilled(false);
			MoodMonth11.add(MonthBtn[10][i]);
			if (i < 30) {
				if (i <= 8) {
					if ((11 < monthMood) || (11 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[10][i].addActionListener(new MyActionListener("110" + Integer.toString(i + 1)));
					}
				} else {
					if ((11 < monthMood) || (11 == monthMood && i + 1 <= dayMood)) {
						MonthBtn[10][i].addActionListener(new MyActionListener("11" + Integer.toString(i + 1)));
					}
				}
			} else {
				MonthBtn[1][i].setEnabled(false);
			}
		}

		// Month : 12 (Panel)

		MoodMonth12.setLayout(new GridLayout(5, 7));
		MoodMonth12.setBounds(175, 100, 924, 544);
		MoodPanel.add(MoodMonth12);
		MoodMonth12.setVisible(false);
		MonthBtn[11] = new JButton[31];

		for (int i = 0; i < MonthBtn[11].length; i++) {
			MonthBtn[11][i] = new JButton();
			MonthBtn[11][i].setBorderPainted(false);
			MonthBtn[11][i].setContentAreaFilled(false);
			MoodMonth12.add(MonthBtn[11][i]);
			if (i <= 8) {
				if ((12 < monthMood) || (12 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[11][i].addActionListener(new MyActionListener("120" + Integer.toString(i + 1)));
				}
			} else {
				if ((12 < monthMood) || (12 == monthMood && i + 1 <= dayMood)) {
					MonthBtn[11][i].addActionListener(new MyActionListener("12" + Integer.toString(i + 1)));
				}
			}
		}

		ImageIcon[] iconList = new ImageIcon[6];
		iconList[0] = new ImageIcon("./data/images/mood/happy.png");
		iconList[1] = new ImageIcon("./data/images/mood/good.png");
		iconList[2] = new ImageIcon("./data/images/mood/tired.png");
		iconList[3] = new ImageIcon("./data/images/mood/bad.png");
		iconList[4] = new ImageIcon("./data/images/mood/sad.png");
		iconList[5] = new ImageIcon("./data/images/mood/sick.png");
		ImageIcon icon;
		Image img;
		int moodIndex = 0;
		ArrayList<Integer> changeMonth = new ArrayList<Integer>();
		ArrayList<Integer> changeDay = new ArrayList<Integer>();
		ArrayList<Integer> moodNumber = new ArrayList<Integer>();
		// if Mood save DB, then icon is image
		String path = "./data/moodDB";
		File dir = new File(path);
		File[] fileList = dir.listFiles();
		for (File file : fileList) {
			if (file.isFile()) {
				String fileName = file.getName();

				File moodFile = new File(path + "/" + fileName);

				int Idx = fileName.lastIndexOf(".");
				String _fileName = fileName.substring(0, Idx);

				changeMonth.add(Integer.parseInt(_fileName) / 100);
				changeDay.add(Integer.parseInt(_fileName) - changeMonth.get(moodIndex) * 100);
				moodIndex++;

				try {
					FileReader filereadar = new FileReader(moodFile);

					BufferedReader bufReader = new BufferedReader(filereadar);
					String line = "";

					while ((line = bufReader.readLine()) != null) {
						moodNumber.add(Integer.parseInt(line));
					}
					bufReader.close();
					for (int i = 0; i < changeMonth.size(); i++) {
						icon = iconList[moodNumber.get(i)];
						img = icon.getImage().getScaledInstance(100, 100, Image.SCALE_SMOOTH);
						MonthBtn[changeMonth.get(i) - 1][changeDay.get(i) - 1].setIcon(new ImageIcon(img));
					}

				} catch (FileNotFoundException e1) {
					System.out.println(e1);
				} catch (IOException e1) {
					System.out.println(e1);
				}
			}
		}

		// Mood page Add Calendar (button, label)
		JLabel yearLB = new JLabel(Integer.toString(yearMood));
		JLabel monthLB = new JLabel();

		if (monthMood - 10 < 0) {
			monthLB.setText("0" + Integer.toString(monthMood));
		} else {
			monthLB.setText(Integer.toString(monthMood));
		}

		JButton prevMonthBtn = new JButton("◀");
		JButton nextMonthBtn = new JButton("▶");

		yearLB.setBounds(1127, 22, 100, 46);
		yearLB.setFont(new Font("나눔 고딕", Font.BOLD, 15));

		monthLB.setBounds(1126, 50, 50, 46);
		monthLB.setFont(new Font("나눔 고딕", Font.BOLD, 30));

		prevMonthBtn.setBounds(1070, 36, 70, 46);
		prevMonthBtn.setBorderPainted(false);
		prevMonthBtn.setContentAreaFilled(false);
		prevMonthBtn.setFont(new Font("나눔 고딕", Font.BOLD, 25));

		nextMonthBtn.setBounds(1147, 36, 70, 46);
		nextMonthBtn.setBorderPainted(false);
		nextMonthBtn.setContentAreaFilled(false);
		nextMonthBtn.setFont(new Font("나눔 고딕", Font.BOLD, 25));

		MoodPanel.add(yearLB);
		MoodPanel.add(monthLB);
		MoodPanel.add(prevMonthBtn);
		MoodPanel.add(nextMonthBtn);

		prevMonthBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				CloseOpenMonth(monthMood, false);

				PrevMonth prevMonth = new PrevMonth(yearMood, monthMood);

				yearMood = prevMonth.getYear();
				monthMood = prevMonth.getMonth();

				yearLB.setText(Integer.toString(yearMood));

				if (monthMood - 10 < 0) {
					monthLB.setText("0" + Integer.toString(monthMood));
				} else {
					monthLB.setText(Integer.toString(monthMood));
				}

				CloseOpenMonth(monthMood, true);

			}

			void CloseOpenMonth(int month, Boolean state) {
				switch (month) {
				case 1:
					MoodMonth01.setVisible(state);
					break;
				case 2:
					MoodMonth02.setVisible(state);
					break;
				case 3:
					MoodMonth03.setVisible(state);
					break;
				case 4:
					MoodMonth04.setVisible(state);
					break;
				case 5:
					MoodMonth05.setVisible(state);
					break;
				case 6:
					MoodMonth06.setVisible(state);
					break;
				case 7:
					MoodMonth07.setVisible(state);
					break;
				case 8:
					MoodMonth08.setVisible(state);
					break;
				case 9:
					MoodMonth09.setVisible(state);
					break;
				case 10:
					MoodMonth10.setVisible(state);
					break;
				case 11:
					MoodMonth11.setVisible(state);
					break;
				case 12:
					MoodMonth12.setVisible(state);
					break;
				}
			}
		});

		nextMonthBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				CloseOpenMonth(monthMood, false);

				NextMonth nextMonth = new NextMonth(yearMood, monthMood);

				yearMood = nextMonth.getYear();
				monthMood = nextMonth.getMonth();

				yearLB.setText(Integer.toString(yearMood));

				if (monthMood - 10 < 0) {
					monthLB.setText("0" + Integer.toString(monthMood));
				} else {
					monthLB.setText(Integer.toString(monthMood));
				}

				CloseOpenMonth(monthMood, true);
			}

			void CloseOpenMonth(int month, Boolean state) {
				switch (month) {
				case 1:
					MoodMonth01.setVisible(state);
					break;
				case 2:
					MoodMonth02.setVisible(state);
					break;
				case 3:
					MoodMonth03.setVisible(state);
					break;
				case 4:
					MoodMonth04.setVisible(state);
					break;
				case 5:
					MoodMonth05.setVisible(state);
					break;
				case 6:
					MoodMonth06.setVisible(state);
					break;
				case 7:
					MoodMonth07.setVisible(state);
					break;
				case 8:
					MoodMonth08.setVisible(state);
					break;
				case 9:
					MoodMonth09.setVisible(state);
					break;
				case 10:
					MoodMonth10.setVisible(state);
					break;
				case 11:
					MoodMonth11.setVisible(state);
					break;
				case 12:
					MoodMonth12.setVisible(state);
					break;
				}
			}
		});

		moodgoToMenubtn.setBounds(1214, 22, 48, 46);
		moodgoToMenubtn.setBorderPainted(false);
		moodgoToMenubtn.setContentAreaFilled(false);
		MoodPanel.add(moodgoToMenubtn);

		moodgoToMenubtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				monthMood = date.get(Calendar.MONTH) + 1;
				if (monthMood - 10 < 0) {
					monthLB.setText("0" + Integer.toString(monthMood));
				} else {
					monthLB.setText(Integer.toString(monthMood));
				}

				MoodMonth01.setVisible(false);
				MoodMonth02.setVisible(false);
				MoodMonth03.setVisible(false);
				MoodMonth04.setVisible(false);
				MoodMonth05.setVisible(false);
				MoodMonth06.setVisible(false);
				MoodMonth07.setVisible(false);
				MoodMonth08.setVisible(false);
				MoodMonth09.setVisible(false);
				MoodMonth10.setVisible(false);
				MoodMonth11.setVisible(false);
				MoodMonth12.setVisible(false);

				MoodPanel.setVisible(false);
				menuPanel.setVisible(true);

			}
		});

		// Change Mood
		JButton moodChange = new JButton();
		moodChange.setIcon(new ImageIcon("./data/images/Icon/Update.png"));
		moodChange.setBounds(999, 30, 66, 60);
		moodChange.setBorderPainted(false);
		moodChange.setContentAreaFilled(false);
		moodChange.setFont(new Font("�굹�닎 怨좊뵓", Font.BOLD, 10));
		MoodPanel.add(moodChange);

		moodChange.addActionListener(new ActionListener() {
			ImageIcon icon;
			Image img;

			@Override
			public void actionPerformed(ActionEvent e) {
				String path = "./data/moodDB";
				File dir = new File(path);
				File[] fileList = dir.listFiles();

				ImageIcon[] iconList = new ImageIcon[6];
				iconList[0] = new ImageIcon("./data/images/mood/happy.png");
				iconList[1] = new ImageIcon("./data/images/mood/good.png");
				iconList[2] = new ImageIcon("./data/images/mood/tired.png");
				iconList[3] = new ImageIcon("./data/images/mood/bad.png");
				iconList[4] = new ImageIcon("./data/images/mood/sad.png");
				iconList[5] = new ImageIcon("./data/images/mood/sick.png");
				ImageIcon icon;
				Image img;
				int moodIndex = 0;
				ArrayList<Integer> changeMonth = new ArrayList<Integer>();
				ArrayList<Integer> changeDay = new ArrayList<Integer>();
				ArrayList<Integer> moodNumber = new ArrayList<Integer>();

				for (File file : fileList) {
					if (file.isFile()) {
						String fileName = file.getName();

						File moodFile = new File(path + "/" + fileName);

						int Idx = fileName.lastIndexOf(".");
						String _fileName = fileName.substring(0, Idx);

						changeMonth.add(Integer.parseInt(_fileName) / 100);
						changeDay.add(Integer.parseInt(_fileName) - changeMonth.get(moodIndex) * 100);
						moodIndex++;

						try {
							FileReader filereadar = new FileReader(moodFile);

							BufferedReader bufReader = new BufferedReader(filereadar);
							String line = "";

							while ((line = bufReader.readLine()) != null) {
								moodNumber.add(Integer.parseInt(line));
							}
							bufReader.close();
							for (int i = 0; i < changeMonth.size(); i++) {
								icon = iconList[moodNumber.get(i)];
								img = icon.getImage().getScaledInstance(100, 100, Image.SCALE_SMOOTH);
								MonthBtn[changeMonth.get(i) - 1][changeDay.get(i) - 1].setIcon(new ImageIcon(img));
							}
						} catch (FileNotFoundException e1) {
							System.out.println(e1);
						} catch (IOException e1) {
							System.out.println(e1);
						}
					}
				}
			}
		});

		goToMenu.setBounds(431, 402, 483, 71);
		startPanel.add(goToMenu);
		goToMenu.setBorderPainted(false);
		goToMenu.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				startPanel.setVisible(false);
				menuPanel.setVisible(true);
			}
		});
		goToMenu.setFont(new Font("나눔손글씨 가람연꽃", Font.PLAIN, 24));

		Image temp = new ImageIcon("./data/images/Icon/Daily_click.png").getImage();
		Image change = temp.getScaledInstance(224, 125, Image.SCALE_SMOOTH);
		ImageIcon tempicon = new ImageIcon(change);

		temp = new ImageIcon("./data/images/Icon/Monthly_click.png").getImage();
		change = temp.getScaledInstance(351, 126, Image.SCALE_SMOOTH);
		tempicon = new ImageIcon(change);
		SimpleAttributeSet styleSet = new SimpleAttributeSet();
		StyleConstants.setFontSize(styleSet, 20);

		frame.pack();

		Calendar cal = Calendar.getInstance();
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH) + 1;
		int date = cal.get(Calendar.DATE);
		int lastDay = cal.getActualMaximum(Calendar.DATE);
		ArrayList<Integer> calArr = new ArrayList<>();

		for (int i = 0; i < lastDay; i++) {
			calArr.add(i + 1);
		}

	}
}

class MyActionListener implements ActionListener {

	String day;

	MyActionListener(String day) {
		this.day = day;
	}

	public void actionPerformed(ActionEvent e) {
		new EmotionFrame(day);
	}

}