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
	private String[] cities = {"런던", "파리", "시드니", "로스앤젤레스", "뉴욕", "취리히", "벤쿠버"};
	
	public ListTest() {
		// TODO Auto-generated constructor stub
		setTitle("리스트");
		setSize(300, 200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel listPanel = new JPanel();
		JPanel panel = new JPanel();
		list = new JList(cities);
		
		//리스트에 경계선을 설정
		list.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
		//리스트에 스크롤 바를 추가
		JScrollPane scroller = new JScrollPane(list);
		scroller.setPreferredSize(new Dimension(200, 100));
		//리스트의 선택모드를 단일 선택모드로 변경
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		list.addListSelectionListener(new ListListener());
		
		label = new JLabel("선택된 항목 : ");
		selected = new JTextField(10);
		
		//텍스트 필드를 편집 불가로 설정한다
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
			//선택된 도시를 얻는다
			String selection = (String) list.getSelectedValue();
			//선택된 도시를 텍스트 필드에 기록
			selected.setText(selection);
		}
	}
	
	public static void main(String[] args) {
		ListTest frame = new ListTest();
	}
}
