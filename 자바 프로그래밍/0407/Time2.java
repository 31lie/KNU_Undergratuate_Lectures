// 2020114658 이윤서
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

public class Time2 {
    private int second;

    public Time2() {
        this(0, 0, 0);
    }

    public Time2(int hour) {
        this(hour, 0, 0);
    }

    public Time2(int hour, int minute) {
        this(hour, minute, 0);
    }

    public Time2(int hour, int minute, int second) {
        if (hour < 0 || hour >= 24) {
            throw new IllegalArgumentException("hour must be 0-23");
        }

        if (minute < 0 || minute >= 60) {
            throw new IllegalArgumentException("minute must be 0-59");
        }

        if (second < 0 || second >= 60) {
            throw new IllegalArgumentException("second must be 0-59");
        }

        this.second = 3600 * hour + 60 * minute + second;
    }

    public Time2(Time2 time) {
        this.second = time.second;
    }

    public int getSecond() {
        return second;
    }

    public String toUniversalString() {
    	
        int temp = getSecond();
        int hour;
        int minute;
        int second;

        hour = temp / 3600;
        temp = temp % 3600;
        
        minute = temp / 60;
        temp = temp % 60;

        second = temp;

        return String.format("%02d:%02d:%02d", hour, minute, second);
    }

    public String toString() {
        int temp = getSecond();
        int hour;
        int minute;
        int second;

        hour = temp / 3600;
        temp = temp % 3600;
        
        minute = temp / 60;
        temp = temp % 60;

        second = temp;

        return String.format("%d:%02d:%02d %s", ((hour == 0 || hour == 12) ? 12 : hour % 12), minute, second, (hour >= 12 ? "PM" : "AM"));
    }
}