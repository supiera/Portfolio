package Report;

import java.awt.GridLayout;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.ImageIcon;
import javax.swing.JCheckBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class CheckBoxTest extends JPanel implements ItemListener{
	
	JCheckBox[] btns = new JCheckBox[3];	//버튼
	String[] fruits = {"apple", "grape", "orange"};
	JLabel[] pictureLabel = new JLabel[3];
	ImageIcon[] icon = new ImageIcon[3];
	
	public CheckBoxTest() {
		// TODO Auto-generated constructor stub
		super(new GridLayout(0,4));
		
		//체크 박스를 생성
		for(int i = 0; i<3; i++){
			btns[i] = new JCheckBox(fruits[i]);
			btns[i].addItemListener(this);		//체크박스에 아이템 리스너를 등록
			pictureLabel[i] = new JLabel(fruits[i] + ".gif");
			icon[i] = new ImageIcon(fruits[i] + ".gif");
		}
		
		JPanel checkPanel = new JPanel(new GridLayout(0, 1));
		for(int i = 0; i<3; i++)
			checkPanel.add(btns[i]);
		
		add(checkPanel);
		add(pictureLabel[0]);	//apple
		add(pictureLabel[1]);	//grape
		add(pictureLabel[2]);	//orange
	}
	
	@Override
	public void itemStateChanged(ItemEvent e) {
		// TODO Auto-generated method stub
		ImageIcon image = null;
		Object source = e.getItemSelectable();		//선택된 체크박스들을 얻어온다.
		for(int i = 0; i<3; i++){
			if(source == btns[i]){
				if(e.getStateChange() == ItemEvent.DESELECTED)		//체크박스가 해제되었으면
					pictureLabel[i].setIcon(null);		//아이콘을 없앤다
				else		//체크박스가 되어있으면
					pictureLabel[i].setIcon(icon[i]);		//아이콘을 보여준다
			}
		}
	}
	
	public static void main(String args[]){
		JFrame frame = new JFrame("CheckBoxDemo");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JComponent newContentPane = new CheckBoxTest();
		newContentPane.setOpaque(true);
		frame.setContentPane(newContentPane);
		frame.setSize(500, 200);
		frame.setVisible(true);
	}

}
