package application;

import java.io.*;
import java.util.Calendar;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

import java.net.MalformedURLException;
import java.net.URL;

public class Util {
	public static final String getJongsung(String str) {
		String firstValue = "이";
		String secondValue = "가";

		char lastChar = str.charAt(str.length() - 1);

		if (lastChar < 0xAC00 || lastChar > 0xD7A3) {
			return str;
		}
		String seletedValue = (lastChar - 0xAC00) % 28 > 0 ? firstValue : secondValue;
		return str + seletedValue;
	}

	public static void makeMp3(String text, String mp3Name) {
		String clientId = "z0o3wzmosv";
		String clientSecret = "yzeG0RgDKzGgjChkU35QCK24yt9nz1iJ8AYBFqWe";
		try {
			text = URLEncoder.encode(text, "UTF-8");
			String apiURL = "https://naveropenapi.apigw.ntruss.com/tts-premium/v1/tts";
			URL url = new URL(apiURL);
			HttpURLConnection con = (HttpURLConnection) url.openConnection();
			con.setRequestMethod("POST");
			con.setRequestProperty("X-NCP-APIGW-API-KEY-ID", clientId);
			con.setRequestProperty("X-NCP-APIGW-API-KEY", clientSecret);
			String postParams = "speaker=ndain&volume=0&speed=0&pitch=0&format=wav&text=" + text;
			con.setDoOutput(true);
			DataOutputStream wr = new DataOutputStream(con.getOutputStream());
			wr.writeBytes(postParams);
			wr.flush();
			wr.close();
			int responseCode = con.getResponseCode();
			BufferedReader br;
			if (responseCode == 200) {
				InputStream is = con.getInputStream();
				int read = 0;
				byte[] bytes = new byte[1024];
				File f = new File("./data/sound/" + mp3Name + ".wav");
				f.createNewFile();
				OutputStream outputStream = new FileOutputStream(f);
				while ((read = is.read(bytes)) != -1) {
					outputStream.write(bytes, 0, read);
				}
				is.close();
			} else {
				br = new BufferedReader(new InputStreamReader(con.getErrorStream()));
				String inputLine;
				StringBuffer response = new StringBuffer();
				while ((inputLine = br.readLine()) != null) {
					response.append(inputLine);
				}
				br.close();
				System.out.println(response.toString());
			}
		} catch (Exception e) {
			System.out.println(e);
		}
	}

	public static int getTodayYear() {
		Calendar calendar = Calendar.getInstance();
		return calendar.get(Calendar.YEAR);
	}

	public static int getTodayMonth() {
		Calendar calendar = Calendar.getInstance();
		return calendar.get(Calendar.MONTH) + 1;
	}

	public static int getTodayDay() {
		Calendar calendar = Calendar.getInstance();
		return calendar.get(Calendar.DAY_OF_MONTH);
	}
}
