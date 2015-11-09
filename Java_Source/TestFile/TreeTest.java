package Report;

import javax.swing.*;

import java.awt.event.*;
import javax.swing.tree.*;
import javax.swing.event.*;

public class TreeTest extends JFrame {
	private JTree tree;
	private JLabel label;
	
	public TreeTest() {
		this.setSize(400, 300);
		this.setTitle("트리 테스트");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		DefaultMutableTreeNode root = new DefaultMutableTreeNode("나의 문서함");
		DefaultMutableTreeNode child1 = new DefaultMutableTreeNode("편지");
		DefaultMutableTreeNode child2 = new DefaultMutableTreeNode("음악");
		DefaultMutableTreeNode child3 = new DefaultMutableTreeNode("한국");
		DefaultMutableTreeNode child4 = new DefaultMutableTreeNode("전통");
		DefaultMutableTreeNode child5 = new DefaultMutableTreeNode("힙팝");
		DefaultMutableTreeNode child6 = new DefaultMutableTreeNode("외국");
		DefaultMutableTreeNode child7 = new DefaultMutableTreeNode("소설");
		DefaultMutableTreeNode child8 = new DefaultMutableTreeNode("추리");
		
		// 계층 관계 생성
		root.add(child1);
		root.add(child2);
		root.add(child7);
		
		child2.add(child3);
		child2.add(child6);
		child3.add(child4);
		child3.add(child5);
		child7.add(child8);
		
		//트리생성
		tree = new JTree(root);

		tree.setVisibleRowCount(10);
		tree.addTreeSelectionListener(new TreeListener());

		JPanel panel = new JPanel();
		JScrollPane scroll = new JScrollPane(tree);
		panel.add(scroll);

		label = new JLabel();
		panel.add(label);
		add(panel);

		this.setVisible(true);
	}

	private class TreeListener implements TreeSelectionListener {
		public void valueChanged(TreeSelectionEvent e) {
			DefaultMutableTreeNode node = (DefaultMutableTreeNode) tree
					.getLastSelectedPathComponent();
			if (node == null)
				return;
			String s = (String) node.getUserObject();
			label.setText(s);
		}
	}

	public static void main(String[] args) {
		try {
			UIManager
					.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
		} catch (Exception e) {
			e.printStackTrace();
		}
		new TreeTest();
	}

}
