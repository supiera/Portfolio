package Report;

import java.util.Calendar;
import java.util.Date;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.SpinnerDateModel;
import javax.swing.SpinnerListModel;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;

public class SpinnerTest extends JFrame{
	public SpinnerTest() {
		// TODO Auto-generated constructor stub
		setTitle("���ǳ� �׽�Ʈ");
		setSize(500, 100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		JSpinner spinner;
		
		//List Model Test
		String[] items = {"�Ҽ�", "����", "��������", "���"};
		SpinnerListModel listModel = new SpinnerListModel(items);
		spinner = new JSpinner(listModel);
		panel.add(spinner);
		
		//Number Model Test
		SpinnerModel numberModel = new SpinnerNumberModel(1, 0, 9, 1);
		spinner = new JSpinner(numberModel);
		panel.add(spinner);
		
		//Date Model Test
		Calendar calendar = Calendar.getInstance();
		Date value = calendar.getTime();		//���� ��¥
		calendar.add(Calendar.YEAR, -50);
		Date start = calendar.getTime();		//���� ��¥
		calendar.add(Calendar.YEAR, 100);
		Date end = calendar.getTime();
		SpinnerDateModel dateModel = new SpinnerDateModel(value, start, end, Calendar.YEAR);
		spinner = new JSpinner(dateModel);
		
		//��¥�� ������ �� �ִ� ������ ����
		spinner.setEditor(new JSpinner.DateEditor(spinner, "yyyy/MM/dd"));
		panel.add(spinner);
		add(panel);
		setVisible(true);
	}
	public static void main(String[] args) {
		new SpinnerTest();
	}
}