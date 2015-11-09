package Report;

import javax.swing.*;
import java.awt.*;
import javax.swing.event.*;
import javax.swing.table.TableColumn;
import javax.swing.table.TableModel;

public class SimpleTableTest extends JFrame implements TableModelListener{
	public SimpleTableTest(){

		String[] columnNames ={"�̸�", "�ּ�", "����", "���Կ���"};

		Object[][] data ={{"��ö��", "����", new Integer(24), new Boolean(false)},
						{"�迵��", "�λ�", new Integer(25), new Boolean(true)},
						{"������", "õ��", new Integer(32), new Boolean(false)}};
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(500, 200);
		
		final JTable table = new JTable(data, columnNames);
		table.setPreferredScrollableViewportSize(new Dimension(500, 150));
		table.setFillsViewportHeight(true);

		table.getModel().addTableModelListener(this);
		table.setAutoCreateRowSorter(true);

		TableColumn cityColumn = table.getColumnModel().getColumn(1);
		JComboBox comboBox = new JComboBox();
		comboBox.addItem("����");
		comboBox.addItem("�λ�");
		comboBox.addItem("����");
		comboBox.addItem("�뱸");
		comboBox.addItem("����");
		comboBox.addItem("õ��");
		cityColumn.setCellEditor(new DefaultCellEditor(comboBox));

		JScrollPane scrollPane = new JScrollPane(table);
		add(scrollPane);
		setVisible(true);
	}

	public void tableChanged(TableModelEvent e){
		int row = e.getFirstRow();
		int column = e.getColumn();
		if (column == 2){
			TableModel model = (TableModel) e.getSource();
			String columnName = model.getColumnName(column);
			Object data = model.getValueAt(row, column);
			String s = (String) data;
			if (Integer.parseInt(s)>100)
				JOptionPane.showMessageDialog(this, "������ �ʰ��Ͽ����ϴ�: " + s, "���", JOptionPane.WARNING_MESSAGE);
		}
	}

	public static void main(String[] args){
		new SimpleTableTest();
	}
}
