package application;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Schedule implements Comparable<Schedule> {
	private String content;
	private SimpleDateFormat f = new SimpleDateFormat("HH:mm-HH:mm");
	private Date d;
	private String tag;

	private int startHour;
	private int startMin;

	private int finishHour;
	private int finishMin;

	private int ID;

	public Schedule(String content, String tag, int startHour, int startMin, int finishHour, int finishMin) {
		this.content = content;
		this.tag = tag;
	
		try {
			this.d = f.parse(startHour + ":" + startMin + "-" + finishHour + ":" + finishMin);
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		
		this.startHour = startHour;
		this.startMin = startMin;

		this.finishHour = finishHour;
		this.finishMin = finishMin;
	}

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}

	public int getStartHour() {
		return startHour;
	}

	public void setStartHour(int startHour) {
		this.startHour = startHour;
	}

	public int getStartMin() {
		return startMin;
	}

	public void setStartMin(int startMin) {
		this.startMin = startMin;
	}

	public int getFinishHour() {
		return finishHour;
	}

	public void setFinishHour(int finishHour) {
		this.finishHour = finishHour;
	}

	public int getFinishMin() {
		return finishMin;
	}

	public void setFinishMin(int finishMin) {
		this.finishMin = finishMin;
	}

	public String getStartTime() {
		if (this.getStartMin() == 0) {
			return String.format("%s시", getStartHour());
		} else {
			return String.format("%s시 %s분", getStartHour(), getStartMin());
		}
	}

	public String getFinishTime() {
		if (this.getFinishMin() == 0) {
			return String.format("%s시", getFinishHour());
		} else {
			return String.format("%s시 %s분", getFinishHour(), getFinishMin());
		}
	}

	public String getTag() {
		return tag;
	}

	@Override
	public int compareTo(Schedule s) {
		return this.d.compareTo(s.d);
	}

	public String toString() {
		return String.format("%s부터 %s까지 %s 있습니다. ", this.getStartTime(), this.getFinishTime(),
				Util.getJongsung(this.getContent()));
	}
}
