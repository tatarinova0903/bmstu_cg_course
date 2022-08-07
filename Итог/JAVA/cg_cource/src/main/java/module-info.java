module com.example.cg_cource {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.cg_cource to javafx.fxml;
    exports com.example.cg_cource;
    exports com.example.cg_cource.MainSceneModule;
    opens com.example.cg_cource.MainSceneModule to javafx.fxml;
    exports com.example.cg_cource.Helpers;
    opens com.example.cg_cource.Helpers to javafx.fxml;
    exports com.example.cg_cource.Objects;
    opens com.example.cg_cource.Objects to javafx.fxml;
    exports com.example.cg_cource.Views;
    opens com.example.cg_cource.Views to javafx.fxml;
}