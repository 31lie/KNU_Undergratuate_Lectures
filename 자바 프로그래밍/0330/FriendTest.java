//2020114658 이윤서
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.



class Friend{
	
	String name;
	int age;
	
	public Friend(String name, int age){
		this.name = name;
		this.age = age;
	}
	
	public String getName() {
		return this.name;
	}
	
	public int getAge() {
		return this.age;
	}
}


public class FriendTest {

	public static void main(String[] args) {
		
		// 아래 데이터를 이용해야함
		String[] names = {"전정국","정호석","김남준"};
		int[] ages = {1997, 1994, 1994};
		
		//객체배열 생성, for문 이용
		Friend[] friends = new Friend[3];
		for (int i=0;i<names.length;i++) {
			friends[i] = new Friend(names[i],ages[i]);
		}
		
		//counter controlled for문을 사용한 객체 정보 출력,
		//System.out.printf 메소드 사용, Friend의 toString이 암묵적으로 호출됨
		for (int i=0;i<names.length;i++) {
			System.out.printf("%s%n",friends[i].getName()+friends[i].getAge());
		}
		
		//enhanced for문을 사용한 객체 정보 출력,
		//System.out.printf 메소드 사용, Friend의 toString이 암묵적으로 호출됨
		for (Friend p:friends) {
			System.out.printf("%s%n",p.getName()+p.getAge());
		}
	}	
	

}
