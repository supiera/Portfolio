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
		setTitle("�ݾװ� ��¥ �Է¹ޱ�");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		amountLabel = new JLabel("�ݾ� : ");
		dateLabel = new JLabel("��¥ : ");
		
		//���ڸ� �Է¹����� �ִ� �ؽ�Ʈ �ʵ� ���� �� �Ӽ� ����
		amountField = new JFormattedTextField(new NumberFormatter());
		amountField.setValue(new Integer(100));
		amountField.setColumns(10);
		amountField.addPropertyChangeListener("value", this);
		
		//��¥�� �Է¹��� �� �ִ� �ؽ�Ʈ �ʵ� ���� �� �Ӽ� ����
		dateField = new JFormattedTextField(new DateFormatter());
		dateField.setValue(new Date());
		dateField.setColumns(10);
		dateField.addPropertyChangeListener("value", this);
		
		// �гο� ����ȭ �ؽ�Ʈ �ʵ带 ��ġ�Ѵ�.
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
	//�ؽ�Ʈ �ʵ��� value �Ӽ��� ����Ǹ� ȣ��ȴ�.
	public void propertyChange(PropertyChangeEvent e){
		Object source = e.getSource();	//���� �о�´�.
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
