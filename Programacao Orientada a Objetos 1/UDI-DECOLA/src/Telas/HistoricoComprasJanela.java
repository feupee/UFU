package Telas;

import javax.swing.*;
import javax.swing.table.AbstractTableModel;
import Util.Compras;
import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.List;

public class HistoricoComprasJanela extends JFrame {
    public class HistoricoComprasTableModel extends AbstractTableModel {

        private List<Compras> compras;
        private String[] columnNames = {"Tipo de Compra", "Data da Compra", "Valor Total"}; // Nova coluna para o tipo de compra

        public HistoricoComprasTableModel(List<Compras> compras) {
            this.compras = compras;
        }

        @Override
        public int getRowCount() {
            return compras.size();
        }

        @Override
        public int getColumnCount() {
            return columnNames.length;
        }

        @Override
        public String getColumnName(int column) {
            return columnNames[column];
        }

        @Override
        public Object getValueAt(int rowIndex, int columnIndex) {
            Compras compra = compras.get(rowIndex);
            switch (columnIndex) {
                case 0:
                    return compra.getTipoCompra(); // Nova coluna para o tipo de compra
                case 1:
                    SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
                    return dateFormat.format(compra.getDataHoraCompra());
                case 2:
                    return compra.getValorTotal();
                default:
                    return null;
            }
        }
    }

    private JTable table;

    public HistoricoComprasJanela(List<Compras> compras) {
        setTitle("Histórico de Compras");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setSize(600, 400);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel(new BorderLayout());

        // Cria o modelo da tabela
        HistoricoComprasTableModel model = new HistoricoComprasTableModel(compras);
        table = new JTable(model);

        JScrollPane scrollPane = new JScrollPane(table);
        panel.add(scrollPane, BorderLayout.CENTER);

        getContentPane().add(panel);
    }
}