module com.example.cg_cource_2 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.cg_cource_2 to javafx.fxml;
    exports com.example.cg_cource_2;
}