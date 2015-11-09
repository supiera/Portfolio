package csp.shinhan.ac.kr.teamintroduction;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.google.gson.Gson;


public class MainActivity extends Activity {

    private EditText loginAccountText;
    private EditText loginPasswordText;
    private EditText signupAccountText;
    private EditText signupPasswordText;
    private EditText signupNickNameText;

    private Button loginButton;
    private Button signupButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.loginAccountText = (EditText)findViewById(R.id.accountText);
        this.loginPasswordText = (EditText)findViewById(R.id.passwordText);
        this.signupAccountText = (EditText)findViewById(R.id.signUpAccountText);
        this.signupPasswordText = (EditText)findViewById(R.id.signUpPasswordText);
        this.signupNickNameText = (EditText)findViewById(R.id.signUpNameText);

        this.loginButton = (Button)findViewById(R.id.loginButton);
        this.signupButton = (Button)findViewById(R.id.signUpButton);

        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                login();
            }
        });

        signupButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                signup();
            }
        });
    }

    public void login(){

    }

    public void signup(){
        String account = this.signupAccountText.getText().toString();
        String nickName = this.signupNickNameText.getText().toString();
        String password = this.signupPasswordText.getText().toString();

        //객체생성
        UserAccount ua = new UserAccount(account, nickName, password);
        // Json 으로 바꾸기
        String uaJson = new Gson().toJson(ua);

        AsyncTask<String, Void, String> client = new MyRestClient();
        client.execute("POST", "http://shcspkdy.appspot.com/service/UserAccount", uaJson);       //호출, 실행. doinbackground가 호출됨. url은 appspot

        try {
            String s = client.get();
            Result result = new Gson().fromJson(s, Result.class);           //형변환시켜줌

            if(result.isSuccess()){
                //성공메시지 띄워줌. dailogbox로
                AlertDialog.Builder alert = new AlertDialog.Builder(this);
                alert.setMessage("Sign Up Success");        //메시지
                alert.setPositiveButton("OK", new DialogInterface.OnClickListener() {   //메시지 확인 눌렀을 때
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                });
                alert.show();
            } else{
                // 실패
                AlertDialog.Builder alert = new AlertDialog.Builder(this);
                alert.setMessage("Sign Up Fail : " + result.getMessage());        //메시지
                alert.setPositiveButton("OK", new DialogInterface.OnClickListener() {   //메시지 확인 눌렀을 때
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                });
                alert.show();
            }
        } catch(Exception e){e.printStackTrace();}
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
