package application;

import java.util.ArrayList;
import java.net.URLEncoder;

public class ScheduleList {
	public static int id = 1;

	public Day startDay;

	private String text;

	public ArrayList<Schedule> scheduleList = new ArrayList<Schedule>();

	public ScheduleList(Day day) {
		this.startDay = day;
	}

	public void addSchedule(Schedule schedule) {
		scheduleList.add(schedule);
	}

	public void removeAllSchedule() {
		scheduleList.clear();
	}

	public String toString() {
		text = String.format(startDay + " 일정을 말씀 드리겠습니다! ");

		for (Schedule s : scheduleList) {
			text += s.toString();
		}

		return text;
	}
}
