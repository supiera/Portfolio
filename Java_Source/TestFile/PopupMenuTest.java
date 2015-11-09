package Report;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class PopupMenuTest extends JFrame implements ActionListener{
	private JPopupMenu popup;
	private JMenuItem menuItem1, menuItem2;
	private JTextArea ta;

	public PopupMenuTest(){
		ta = new JTextArea(10, 20);
		add(ta);

		popup = new JPopupMenu();
		menuItem1 = new JMenuItem("탐색 메뉴");
		menuItem1.addActionListener(this);
		popup.add(menuItem1);
		
		menuItem2 = new JMenuItem("저장 메뉴");
		menuItem2.addActionListener(this);
		popup.add(menuItem2);

		ta.addMouseListener(new PopupListener());
		setVisible(true);
	}

	class PopupListener extends MouseAdapter{
		public void mousePressed(MouseEvent e){
			showPopup(e);
		}

		public void mouseReleased(MouseEvent e){
			showPopup(e);
		}

		private void showPopup(MouseEvent e){
			if (e.isPopupTrigger())
				popup.show(e.getComponent(), e.getX(), e.getY());
		}
	}

	public void actionPerformed(ActionEvent e){
		if (e.getSource() == menuItem1) 
			JOptionPane.showMessageDialog(this, "탐색이 선택되었습니다.");
	}

	public static void main(String args[]){
		PopupMenuTest f = new PopupMenuTest();
		
		f.setTitle("팝업 메뉴 테스트");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(300, 200);
		f.setVisible(true);
	}
}
