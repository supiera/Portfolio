package Report;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

@SuppressWarnings("serial")
class MyFrame extends JFrame implements ActionListener{
	private JRadioButton small, medium, large;
	private JLabel text;
	private JPanel topPanel, sizePanel, resultPanel;
	
	public MyFrame() {
		// TODO Auto-generated constructor stub
		setTitle("���� ��ư �׽�Ʈ");
		setSize(300, 150);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		topPanel = new JPanel();
		JLabel label = new JLabel("� ũ���� Ŀ�Ǹ� �ֹ��Ͻðڽ��ϱ�?");
		topPanel.add(label);
		add(topPanel, BorderLayout.NORTH);
		
		// ���� ��ư�� �����Ѵ�.
		sizePanel = new JPanel();
		small = new JRadioButton("Small Size");
		medium = new JRadioButton("Medium Size");
		large = new JRadioButton("Large Size");
		
		//�׷����
		ButtonGroup size = new ButtonGroup();
		// �׷쿡 ���� ��ư �߰�
		size.add(small);
		size.add(medium);
		size.add(large);
		//��ư�� �׼Ǹ����͸� ���
		small.addActionListener(this);
		medium.addActionListener(this);
		large.addActionListener(this);
		//��ư �׷��� ����, ���� ��ư �߰�
		sizePanel.add(small);
		sizePanel.add(medium);
		sizePanel.add(large);
		add(sizePanel, BorderLayout.CENTER);
		
		resultPanel = new JPanel();
		text = new JLabel("ũ�Ⱑ ���õ��� �ʾҽ��ϴ�.");
		text.setForeground(Color.red);
		resultPanel.add(text);
		add(resultPanel, BorderLayout.SOUTH);
		setVisible(true);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource() == small)
			text.setText("Small Size�� ���õǾ����ϴ�.");
		if(e.getSource() == medium)
			text.setText("Medium Size�� ���õǾ����ϴ�.");
		if(e.getSource() == large)
			text.setText("Large Size�� ���õǾ����ϴ�.");
	}
	
}

@SuppressWarnings("serial")
public class RadioButtonTest extends JFrame{
	public static void main(String[] args){
		new MyFrame();
	}
}
