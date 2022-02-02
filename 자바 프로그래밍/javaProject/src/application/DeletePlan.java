package application;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

public class DeletePlan extends Main {
	JFrame DeleteFrame = new JFrame();
	public static String[][] EachDaySchedule;
	public String selectedDay;
	public int selectedID;

	public DeletePlan() {
		DeleteFrame.setTitle("Delete your Plan");
		DeleteFrame.setVisible(true);
		DeleteFrame.setResizable(false);

		DeleteFrame.getContentPane().setLayout(null);

		String[] PlanDays = new String[DB.dayDB.size()];
		int[] ScheduleCnt = new int[DB.dayDB.size()];
		EachDaySchedule = new String[DB.dayDB.size()][];

		try {
			int i = 0;
			int j;
			for (Day d : DB.dayDB) {
				PlanDays[i] = d.toString();
				ScheduleCnt[i] = DB.searchScheduleList(d).scheduleList.size();
				j = 0;
				EachDaySchedule[i] = new String[ScheduleCnt[i] + 1];
				EachDaySchedule[i][0] = "Delete ALL";
				for (Schedule s : DB.searchScheduleList(d).scheduleList) {
					EachDaySchedule[i][j + 1] = String.format("%02d : %02d ~ %02d : %02d  %s", s.getStartHour(),
							s.getStartMin(), s.getFinishHour(), s.getFinishMin(), s.getContent());
					j++;
				}
				i++;
			}
		} catch (Exception e1) {
			System.out.println(e1);
		}

		JList DayList = new JList(PlanDays);

		DayList.setBorder(null);
		DayList.setFont(new Font("NanumSquareOTF", Font.PLAIN, 24));
		JScrollPane SelectDayPanel = new JScrollPane(DayList);
		SelectDayPanel.setBorder(null);
		SelectDayPanel.setBounds(27, 65, 196, 282);
		DeleteFrame.getContentPane().add(SelectDayPanel);

		JList PlanList = new JList();

		DayList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		PlanList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		PlanList.setBorder(null);

		JScrollPane SelectPlanPanel = new JScrollPane(PlanList);

		SelectPlanPanel.setBounds(250, 65, 273, 282);
		PlanList.setFont(new Font("NanumSquareOTF", Font.PLAIN, 20));
		PlanList.setBorder(null);
		DeleteFrame.getContentPane().add(SelectPlanPanel);

		ImagePanel AddPlanPanel = new ImagePanel(
				new ImageIcon(new File("./data/images/panel_page/DeletePanel.png").getAbsolutePath()).getImage());
		// ImagePanel AddPlanPanel = new ImagePanel(new
		// ImageIcon("/Users/ellie/Desktop/2021-java-programming/data/images/panel_page/DeletePanel.png").getImage());
		DeleteFrame.setSize(AddPlanPanel.getDim());
		DeleteFrame.setPreferredSize(AddPlanPanel.getDim());
		DeleteFrame.getContentPane().add(AddPlanPanel);

		JButton DeletePlanbtn = new JButton("Delete");
		DeletePlanbtn.setBackground(Color.ORANGE);
		DeletePlanbtn.setBounds(438, 18, 84, 29);
		AddPlanPanel.add(DeletePlanbtn);
		DeleteFrame.setLocationRelativeTo(null);

		DeletePlanbtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				selectedDay = (String) DayList.getSelectedValue();
				selectedID = PlanList.getSelectedIndex();
				DB.deleteScheduleFromDB(selectedDay, selectedID);
				DeleteFrame.dispose();
			}
		});

		DayList.addListSelectionListener(new ListSelectionListener() {
			@Override
			public void valueChanged(ListSelectionEvent e) {
				PlanList.setListData(EachDaySchedule[DayList.getSelectedIndex()]);
			}
		});

		PlanList.addListSelectionListener(new ListSelectionListener() {
			@Override
			public void valueChanged(ListSelectionEvent e) {
			}
		});
	}
}
