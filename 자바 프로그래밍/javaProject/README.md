# 2021-java-programming

2021-1 자바프로그래밍 팀 프로젝트

**프로젝트 명** : 당신의 하루를 함께 살아가는 비서, KAILY(Knu dAILY)


# 2021-java-programming

***github repo*** [http://github.com/scv1702/2021-java-programming](http://github.com/scv1702/2021-java-programming)

---

### Team member

- **팀장**   신찬규 *(scv1702) branch: chan*
- **팀원**   이인성 *(ddddddddd122111212) branch: sung*
- **팀원**   이윤서 *(ellie-adm) branch: yoon*
- **팀원**   이지현 *(ljhyeon) branch: hyeon*

---

### Reference

- How to use **GitHub**

    각자 코드 수정한 것들 **백업** 꼭 하기! (매우 중요)

    ```jsx
    **github push 하는 법**
    **처음 설정**
    1. git clone -b master --single-branch http://github.com/scv1702/2021-java-programming
    2. cd 2021-java-programming (clone한 디렉토리로 이동)
    3. git checkout -b {각자 branch 명}
    4. git add .
    5. git commit -m "커밋 내용"
    6. git push origin {각자 branch 명}
    7. github repo 웹페이지 들어가서 master <- 각자 branch로 pull-request

    **설정 후** 
    -- 코드 수정 후 --
    1. git add .
    2. git commit -m "커밋 내용"
    3. git push origin {각자 branch 명}

    **업데이트 한 코드 다운받는 법**
    1. git pull origin master	
    ```

- Document
    - 오디오 녹음에서 화자 구분하기 : [https://cloud.google.com/speech-to-text/docs/multiple-voices?hl=ko#speech_transcribe_diarization_beta-java](https://cloud.google.com/speech-to-text/docs/multiple-voices?hl=ko#speech_transcribe_diarization_beta-java)
    - 네이버 CLOVA Voice : https://api.ncloud-docs.com/docs/ai-naver-clovavoice

---

### IDEA bank

```c
/* **1차시 (2021.05.14) */**
enum participant {신찬규, 이인성 이윤서, 이지현};

****void main() {
		while (!succuess) {
				printf("아이디인 브레인 스토밍");
		}
		printf("프로젝트 제안서 작성");
}
```

- **일정 관리 프로그램**
    - 일정을 관리할 수 있고, 특정 시간을 설정하면 TTS로 일정을 알려준다.
    - + 트래커 까지 합치면 어떨까?
    - 날씨? 너무 갔나?
- **회의록 작성 프로그램 (대면, 비대면 모두 가능)**
    - STT를 이용해 회의가 끝난 후 회의록을 제작할 수 있는 프로그램.
    - 오디오 녹음에서 화자 구분하기 : [https://cloud.google.com/speech-to-text/docs/multiple-voices?hl=ko#speech_transcribe_diarization_beta-java](https://cloud.google.com/speech-to-text/docs/multiple-voices?hl=ko#speech_transcribe_diarization_beta-java)
- **LMS 알림 알려주는 프로그램 (?)**
    - LMS 수업 시간이 특정 시간 남았을 때, TTS로 알려주는 프로그램.

---

- **게임**
- **자동 자막** (STT)
- **보고서 확인** (TTS)
    - 보고서 오타 수정을 위해 읽어주는 프로그램
- 컴퓨터학부 전용 사전
    - CS 용어 사전. TTS로 읽어주는 거? 진짜 사전!

---

### 1차시 결론

- 구현 가능성이 있는 아이디어
    - **일정 관리**: 가장 가능성 있어보이지만 독창성이 떨어진다. → **독창성을 추가**해볼까? +일상 루틴?
        - 구체적인 일정 설정 (시간, 일정)
            - 예) 05/11 07:00 기상 09:00 자바 프로그래밍 13:30 논리회로 15:00 오토마타 및 형식언어
            - 각 일정에 대한 태그 설정
        - 지정한 시간(오전)에 하루 일정 말하기 (TTS)
        - 일정 달성 표시 트래커 (퍼센트게이지)
        - 지정한 시간(오후)에 일정 달성 표시에 따른 멘트(3개) 랜덤 출력 (TTS)
    - 회의록 작성: 구현 난이도가 가장 높지만, 성공하면 매우 좋을듯?
    - LMS 알림 알려주는 프로그램: 난이도가 중간? 크롤링에 대해서 공부만 하면.. 가능할지도


### 기존 앱

- 회의록 작성
    - [https://maum.ai/aiaas/common/files/maum 회의록 서비스 소개서.pdf](https://maum.ai/aiaas/common/files/maum%20%ED%9A%8C%EC%9D%98%EB%A1%9D%20%EC%84%9C%EB%B9%84%EC%8A%A4%20%EC%86%8C%EA%B0%9C%EC%84%9C.pdf)
- 일정관리
    - 에브리타임 (오전 8시에 강의 목록 알림)
    - 타임트리, 구글 캘린더 등을 비롯한 일정 관리 앱
    - 무다
