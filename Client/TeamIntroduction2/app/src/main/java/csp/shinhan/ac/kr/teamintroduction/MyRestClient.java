package csp.shinhan.ac.kr.teamintroduction;

import android.os.AsyncTask;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;

//AsyncTask 를 상속받아서 사용. Rest
public class MyRestClient extends AsyncTask<String, Void, String>{
    @Override
    protected String doInBackground(String... params){          //,,,은 array인데 숫자가 정해지지 않은 것
        String method = params[0];
        String urlString = params[1];
        String json = params[2];        //보낼 제이슨

        String resultString = "";

        //서버로 리퀘스트
        try {
            URL url = new URL(urlString);
            //커넥션 얻어오기
            HttpURLConnection conn = (HttpURLConnection)url.openConnection();
            conn.setRequestProperty("Accept", "application/json");  //줄때 타입 세팅
            conn.setRequestProperty("Content-type", "application/json");  //보낼때 타입 세팅
            conn.setRequestMethod(method);

            //Request
            OutputStream os = conn.getOutputStream();
            os.write(json.getBytes());      //제이슨 스트림을 보냄
            os.flush();

            //Response
            InputStreamReader is = new InputStreamReader(conn.getInputStream());
            BufferedReader br = new BufferedReader(is);
            String s;
            while((s = br.readLine()) != null){
                resultString += s;
            }
        } catch (Exception e){e.printStackTrace();}

        return resultString;
    }
}
