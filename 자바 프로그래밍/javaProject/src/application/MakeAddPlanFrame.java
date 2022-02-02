/*
 * 새로운 일정을 추가하는 프레임을 띄우는 클래스
 * 작성자: 이윤서
 */

package application;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.File;
import java.io.IOException;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class MakeAddPlanFrame extends Main {
	String SelectTag;
	JFrame AddPlanFrame = new JFrame();

	private JTextField planName;
	private JTextField year;
	private JTextField month;
	private JTextField day;
	private JTextField startHour;
	private JTextField startMin;
	private JTextField finishHour;
	private JTextField finishMin;

	public MakeAddPlanFrame() {
		AddPlanFrame.setTitle("Add your Plan");
		AddPlanFrame.setVisible(true);
		AddPlanFrame.setResizable(false);

		// ImagePanel AddPlanPanel = new ImagePanel(new
		// ImageIcon("/Users/ellie/Desktop/2021-java-programming/data/images/panel_page/AddPlanPanel.png").getImage());
		ImagePanel AddPlanPanel = new ImagePanel(
				new ImageIcon(new File("./data/images/panel_page/AddPlanPanel.png").getAbsolutePath()).getImage());
		AddPlanFrame.setSize(AddPlanPanel.getDim());
		AddPlanFrame.setPreferredSize(AddPlanPanel.getDim());
		AddPlanFrame.getContentPane().add(AddPlanPanel);
		AddPlanFrame.setLocationRelativeTo(null);

		planName = new JTextField() {
			@Override
			public void setBorder(Border border) {

			}
		};

		planName.setFont(new Font("NanumSquare", Font.PLAIN, 34));
		planName.setBounds(32, 47, 452, 70);
		planName.setColumns(10);
		planName.setOpaque(false);
		planName.setHorizontalAlignment(JTextField.CENTER);

		AddPlanPanel.add(planName);

		year = new JTextField() {
			@Override
			public void setBorder(Border border) {

			}
		};

		year.setToolTipText("4");
		year.setFont(new Font("NanumSquareOTF", Font.PLAIN, 24));
		year.setBounds(71, 140, 111, 46);
		year.setColumns(10);
		year.setOpaque(false);
		year.setDocument(new jTextFieldLimit(4));
		year.setHorizontalAlignment(JTextField.CENTER);

		AddPlanPanel.add(year);

		month = new JTextField() {
			@Override
			public void setBorder(Border border) {

			}
		};

		month.setFont(new Font("NanumSquare", Font.PLAIN, 24));
		month.setBounds(261, 140, 57, 46);
		month.setColumns(10);
		month.setOpaque(false);
		month.setDocument(new jTextFieldLimit(2));
		month.setHorizontalAlignment(JTextField.CENTER);

		AddPlanPanel.add(month);

		day = new JTextField() {
			@Override
			public void setBorder(Border border) {

			}
		};

		day.setFont(new Font("NanumSquareOTF", Font.PLAIN, 24));
		day.setBounds(378, 140, 57, 46);
		day.setColumns(10);
		day.setOpaque(false);
		day.setDocument(new jTextFieldLimit(2));
		day.setHorizontalAlignment(JTextField.CENTER);

		AddPlanPanel.add(day);

		startHour = new JTextField() {
			@Override
			public void setBorder(Border border) {

			}
		};

		startHour.setFont(new Font("NanumSquareOTF", Font.PLAIN, 24));
		startHour.setBounds(42, 206, 57, 47);
		startHour.setColumns(10);
		startHour.setOpaque(false);
		startHour.setDocument(new jTextFieldLimit(2));
		startHour.setHorizontalAlignment(JTextField.CENTER);

		AddPlanPanel.add(startHour);

		startMin = new JTextField() {
			@Override
			public void setBorder(Border border) {

			}
		};

		startMin.setFont(new Font("NanumSquareOTF", Font.PLAIN, 24));
		startMin.setBounds(144, 206, 57, 47);
		startMin.setColumns(10);
		startMin.setOpaque(false);
		startMin.setDocument(new jTextFieldLimit(2));
		startMin.setHorizontalAlignment(JTextField.CENTER);

		AddPlanPanel.add(startMin);

		finishHour = new JTextField() {
			@Override
			public void setBorder(Border border) {

			}
		};

		finishHour.setFont(new Font("NanumSquareOTF", Font.PLAIN, 24));
		finishHour.setBounds(287, 206, 57, 47);
		finishHour.setColumns(10);
		finishHour.setOpaque(false);
		finishHour.setDocument(new jTextFieldLimit(2));
		finishHour.setHorizontalAlignment(JTextField.CENTER);

		AddPlanPanel.add(finishHour);

		finishMin = new JTextField() {
			@Override
			public void setBorder(Border border) {

			}
		};

		finishMin.setHorizontalAlignment(JTextField.CENTER);
		finishMin.setFont(new Font("NanumSquareOTF", Font.PLAIN, 24));
		finishMin.setBounds(392, 206, 57, 46);
		finishMin.setColumns(10);
		finishMin.setDocument(new jTextFieldLimit(2));
		finishMin.setOpaque(false);

		AddPlanPanel.add(finishMin);

		JButton planSavebtn = new JButton("");
		planSavebtn.setBorderPainted(false);
		planSavebtn.setBounds(215, 595, 97, 46);
		planSavebtn.setOpaque(false);
		AddPlanPanel.add(planSavebtn);

		// Make Tag
		ButtonGroup TagGroup = new ButtonGroup();
		String[] TagName = { "School", "Exam", "Meal", "Appointment", "ETC" };
		JRadioButton TagBtn[] = new JRadioButton[5];

		class MyItemListener implements ItemListener {
			public void itemStateChanged(ItemEvent e) {
				if (e.getStateChange() == ItemEvent.DESELECTED)
					return;
				if (TagBtn[0].isSelected())
					SelectTag = TagName[0];
				else if (TagBtn[1].isSelected())
					SelectTag = TagName[1];
				else if (TagBtn[2].isSelected())
					SelectTag = TagName[2];
				else if (TagBtn[3].isSelected())
					SelectTag = TagName[3];
				else
					SelectTag = TagName[4];
			}
		}

		for (int i = 0; i < TagName.length; i++) {
			TagBtn[i] = new JRadioButton(TagName[i]);
			TagGroup.add(TagBtn[i]);
			TagBtn[i].setFont(new Font("NanumSquareOTF", Font.ITALIC, 17));
			AddPlanPanel.add(TagBtn[i]);
			TagBtn[i].addItemListener(new MyItemListener());
		}

		TagBtn[0].setBounds(178, 315, 97, 23);
		TagBtn[1].setBounds(297, 315, 85, 23);
		TagBtn[2].setBounds(407, 315, 77, 23);
		TagBtn[3].setBounds(178, 359, 140, 23);
		TagBtn[4].setBounds(356, 359, 85, 23);

		planSavebtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String _content = planName.getText();

				int _year = Integer.parseInt(year.getText());
				int _month = Integer.parseInt(month.getText());
				int _day = Integer.parseInt(day.getText());

				int _startHour = Integer.parseInt(startHour.getText());
				int _startMin = Integer.parseInt(startMin.getText());

				int _finishHour = Integer.parseInt(finishHour.getText());
				int _finishMin = Integer.parseInt(finishMin.getText());

				try {
					DB.addScheduleToDB(new Day(_year, _month, _day),
							new Schedule(_content, SelectTag, _startHour, _startMin, _finishHour, _finishMin));
				} catch (IOException e1) {
					e1.printStackTrace();
				}

				/* 창 종료 */
				AddPlanFrame.dispose();
			}
		});
	}
}