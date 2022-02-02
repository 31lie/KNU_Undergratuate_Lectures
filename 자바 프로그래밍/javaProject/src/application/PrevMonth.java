package application;

public class PrevMonth {
	int year;
	int month;

	PrevMonth(int year, int month) {
		this.year = year;
		this.month = month;

		changedMonth();

	}

	void changedMonth() {
		if (month != 1) {
			month--;
		}

	}

	public int getYear() {
		return year;
	}

	public int getMonth() {
		return month;
	}
}
