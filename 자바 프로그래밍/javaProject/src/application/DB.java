package application;

import java.util.Collections;
import java.util.ArrayList;

import java.io.PrintWriter;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.io.IOException;

import java.io.FileFilter;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.File;

import java.io.BufferedReader;
import java.io.FileReader;

public class DB {
	public static ArrayList<Day> dayDB = new ArrayList<Day>();

	public static void updateDayDB() throws IOException {
		dayDB.clear();

		File dir = new File("./data/schedule");
		FileFilter filter = new FileFilter() {
			public boolean accept(File f) {
				return f.getName().endsWith(".txt");
			}
		};

		File[] files = dir.listFiles(filter);
		for (File f : files) {
			String fName = f.getName().replace(".txt", "");
			String[] fNameSubStr = fName.split("-");

			int year = Integer.parseInt(fNameSubStr[0]);
			int month = Integer.parseInt(fNameSubStr[1]);
			int day = Integer.parseInt(fNameSubStr[2]);

			dayDB.add(new Day(year, month, day));
		}

		sortDayDB();
	}

	public static void sortDayDB() {
		Collections.sort(dayDB);
	}

	public static void sortScheduleList(ArrayList<Schedule> l) {
		Collections.sort(l);
	}

	public static void addScheduleToDB(Day day, Schedule schedule) throws IOException {
		String path = "./data/schedule/" + day.getDateTime() + ".txt";
		PrintWriter pw = new PrintWriter(new FileWriter(path, true));
		String output = String.format("%d, %d, %d, %d, %s, %s", schedule.getStartHour(), schedule.getStartMin(),
				schedule.getFinishHour(), schedule.getFinishMin(), schedule.getContent(), schedule.getTag());
		pw.println(output);
		pw.flush();
	}

	public static ScheduleList searchScheduleList(Day day) throws IOException {
		ScheduleList sl = new ScheduleList(day);
		String path = "./data/schedule/" + day.getDateTime() + ".txt";

		BufferedReader br = new BufferedReader(new FileReader(path));
		while (true) {
			String line = br.readLine();

			if (line == null)
				break;

			String[] lineSubStr = line.split(", ");

			int startHour = Integer.parseInt(lineSubStr[0]);
			int startMin = Integer.parseInt(lineSubStr[1]);

			int finishHour = Integer.parseInt(lineSubStr[2]);
			int finishMin = Integer.parseInt(lineSubStr[3]);

			String content = lineSubStr[4];
			String tag = lineSubStr[5];

			sl.addSchedule(new Schedule(content, tag, startHour, startMin, finishHour, finishMin));
		}

		sortScheduleList(sl.scheduleList);

		return sl;
	}

	public static void deleteScheduleFromDB(String selectedDay, int selectedID) {
		Date date;
		String fileName;
		String path = "./data/schedule/";
		String dummy = "";
		String line;

		try {
			date = new SimpleDateFormat("yyyy년 MM월 dd일").parse(selectedDay);
			fileName = new SimpleDateFormat("yyyy-MM-dd").format(date);
			path += fileName + ".txt";
			File file = new File(path);

			if (selectedID == 0) {
				file.delete();
				return;
			}

			BufferedReader br = new BufferedReader(new FileReader(path));
			for (int i = 1; i < selectedID; i++) {
				line = br.readLine();
				dummy += line + "\r\n";
			}

			br.readLine();

			while ((line = br.readLine()) != null) {
				dummy += line + "\r\n";
			}

			FileWriter fw = new FileWriter(path);
			fw.write(dummy);
			fw.flush();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
