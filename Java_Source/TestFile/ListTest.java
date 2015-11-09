package Report;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

public class ListTest extends JFrame{
	private JLabel label;
	private JTextField selected;
	private JPanel panel;
	private JList list;
	private String[] cities = {"����", "�ĸ�", "�õ��", "�ν���������", "����", "�븮��", "�����"};
	
	public ListTest() {
		// TODO Auto-generated constructor stub
		setTitle("����Ʈ");
		setSize(300, 200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel listPanel = new JPanel();
		JPanel panel = new JPanel();
		list = new JList(cities);
		
		//����Ʈ�� ��輱�� ����
		list.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
		//����Ʈ�� ��ũ�� �ٸ� �߰�
		JScrollPane scroller = new JScrollPane(list);
		scroller.setPreferredSize(new Dimension(200, 100));
		//����Ʈ�� ���ø�带 ���� ���ø��� ����
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		list.addListSelectionListener(new ListListener());
		
		label = new JLabel("���õ� �׸� : ");
		selected = new JTextField(10);
		
		//�ؽ�Ʈ �ʵ带 ���� �Ұ��� �����Ѵ�
		selected.setEditable(false);
		
		listPanel.add(scroller);
		panel.add(label);
		panel.add(selected);
		add(listPanel, BorderLayout.NORTH);
		add(panel, BorderLayout.CENTER);
		setVisible(true);
	}
	
	private class ListListener implements ListSelectionListener{
		public void valueChanged(ListSelectionEvent e){
			//���õ� ���ø� ��´�
			String selection = (String) list.getSelectedValue();
			//���õ� ���ø� �ؽ�Ʈ �ʵ忡 ���
			selected.setText(selection);
		}
	}
	
	public static void main(String[] args) {
		ListTest frame = new ListTest();
	}
}
