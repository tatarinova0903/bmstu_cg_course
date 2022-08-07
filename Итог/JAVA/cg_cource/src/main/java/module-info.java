module com.example.cg_cource {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.cg_cource to javafx.fxml;
    exports com.example.cg_cource;
    exports com.example.cg_cource.MainSceneModule;
    opens com.example.cg_cource.MainSceneModule to javafx.fxml;
}