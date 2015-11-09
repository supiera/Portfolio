package Report;

import javax.swing.*;
import java.awt.*;
import javax.swing.event.*;
import javax.swing.table.TableColumn;
import javax.swing.table.TableModel;

public class SimpleTableTest extends JFrame implements TableModelListener{
	public SimpleTableTest(){

		String[] columnNames ={"이름", "주소", "나이", "가입여부"};

		Object[][] data ={{"김철수", "서울", new Integer(24), new Boolean(false)},
						{"김영희", "부산", new Integer(25), new Boolean(true)},
						{"이혜정", "천안", new Integer(32), new Boolean(false)}};
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(500, 200);
		
		final JTable table = new JTable(data, columnNames);
		table.setPreferredScrollableViewportSize(new Dimension(500, 150));
		table.setFillsViewportHeight(true);

		table.getModel().addTableModelListener(this);
		table.setAutoCreateRowSorter(true);

		TableColumn cityColumn = table.getColumnModel().getColumn(1);
		JComboBox comboBox = new JComboBox();
		comboBox.addItem("서울");
		comboBox.addItem("부산");
		comboBox.addItem("광주");
		comboBox.addItem("대구");
		comboBox.addItem("대전");
		comboBox.addItem("천안");
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
				JOptionPane.showMessageDialog(this, "범위를 초과하였습니다: " + s, "경고", JOptionPane.WARNING_MESSAGE);
		}
	}

	public static void main(String[] args){
		new SimpleTableTest();
	}
}
