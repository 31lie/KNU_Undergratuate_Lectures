package application;

public class NextMonth {
	int year;
	int month;

	NextMonth(int year, int month) {
		this.year = year;
		this.month = month;

		changedMonth();

	}

	void changedMonth() {
		if (month != 12) {
			month++;
		}
	}

	public int getYear() {
		return year;
	}

	public int getMonth() {
		return month;
	}
}
