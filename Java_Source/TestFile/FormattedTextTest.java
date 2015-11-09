package Report;

import java.awt.BorderLayout;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.util.Date;

import javax.swing.JFormattedTextField;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.text.DateFormatter;
import javax.swing.text.NumberFormatter;


class MyFrame3 extends JFrame implements PropertyChangeListener{
	
	private double amount = 100000;
	private Date date;
	
	private JFormattedTextField amountField;
	private JFormattedTextField dateField;
	
	private JLabel amountLabel, dateLabel;
	
	public MyFrame3() {
		// TODO Auto-generated constructor stub
		setSize(300, 130);
		setTitle("금액과 날짜 입력받기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		amountLabel = new JLabel("금액 : ");
		dateLabel = new JLabel("날짜 : ");
		
		//숫자를 입력받을수 있는 텍스트 필드 생성 및 속성 설정
		amountField = new JFormattedTextField(new NumberFormatter());
		amountField.setValue(new Integer(100));
		amountField.setColumns(10);
		amountField.addPropertyChangeListener("value", this);
		
		//날짜를 입력받을 수 있는 텍스트 필드 생성 및 속성 설정
		dateField = new JFormattedTextField(new DateFormatter());
		dateField.setValue(new Date());
		dateField.setColumns(10);
		dateField.addPropertyChangeListener("value", this);
		
		// 패널에 형식화 텍스트 필드를 배치한다.
		JPanel panel1 = new JPanel();
		JPanel panel2 = new JPanel();
		panel1.add(amountLabel);
		panel1.add(amountField);
		panel2.add(dateLabel);
		panel2.add(dateField);
		add(panel1, BorderLayout.NORTH);
		add(panel2, BorderLayout.CENTER);
		
		setVisible(true);
											
	}
	//텍스트 필드의 value 속성이 변경되면 호출된다.
	public void propertyChange(PropertyChangeEvent e){
		Object source = e.getSource();	//값을 읽어온다.
		if(source == amountField){
			amount = ((Number)amountField.getValue()).doubleValue();
			System.out.println(amount);
		} else if(source == dateField){
			date = (Date) (dateField.getValue());
			System.out.println(date);
		}
	}
}

public class FormattedTextTest {
	public static void main(String[] args){
		new MyFrame3();
	}
}
