package application;

public class Day implements Comparable<Day> {
	private int year;
	private int month;
	private int day;
	private String dateTime;

	public Day(int year, int month, int day) {
		this.year = year;
		this.month = month;
		this.day = day;
		this.dateTime = String.format("%04d-%02d-%02d", year, month, day);
	}

	public Day() {

	}

	public int getYear() {
		return year;
	}

	public int getMonth() {
		return month;
	}

	public int getDay() {
		return day;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public void setMonth(int month) {
		this.month = month;
	}

	public void setDay(int day) {
		this.day = day;
	}

	public String getDateTime() {
		return dateTime;
	}

	@Override
	public String toString() {
		return String.format("%d년 %d월 %d일", getYear(), getMonth(), getDay());
	}

	@Override
	public int compareTo(Day d) {
		return getDateTime().compareTo(d.getDateTime());
	}
}
