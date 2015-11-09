package Report;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

@SuppressWarnings("serial")
class MyFrame2 extends JFrame{
	private JButton btn;
	private JTextField text, result;
	
	public MyFrame2() {
		// TODO Auto-generated constructor stub
		setSize(300, 130);
		setTitle("제곱 계산하기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// 리스터 객체를 생성한다
		ButtonListener listener = new ButtonListener();
		
		JPanel panel = new JPanel();
		panel.add(new JLabel("숫자 입력 : ")); //레이블 객체 생성
		text = new JTextField(15);	//컬럼수가 15인 텍스트 필드 생성
		text.addActionListener(listener);	//텍스트 필드에 액션리스너 등록
		panel.add(text);
		
		panel.add(new JLabel("제곱한 값 :"));
		result = new JTextField(15);	//컬럼수가 15인 결과를 나타낼 텍스트 필드
		result.setEditable(false);		//Read Only로 설정
		panel.add(result);
		
		btn = new JButton("OK");
		btn.addActionListener(listener);
		panel.add(btn);
		add(panel);
		setVisible(true);
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			if(e.getSource() == btn || e.getSource() == text){
				String name = text.getText();
				int value = Integer.parseInt(name);
				result.setText(" " + value * value);
				text.requestFocus();
			}
		}
	}
}

public class TextFieldTest {
	public static void main(String[] args){
		new MyFrame2();
	}
}
