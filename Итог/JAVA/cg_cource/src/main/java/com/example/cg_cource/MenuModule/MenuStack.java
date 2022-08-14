package com.example.cg_cource.MenuModule;

import com.example.cg_cource.Helpers.MenuEvent;
import com.example.cg_cource.MainSceneModule.MainGroup;
import com.example.cg_cource.Views.SmartHBox;
import com.example.cg_cource.Views.SmartVBox;
import com.example.cg_cource.Views.TranslateButton;
import com.example.cg_cource.Views.TranslateButtonType;
import javafx.scene.layout.StackPane;

public class MenuStack extends StackPane {
    MainGroup mainGroup;

    TranslateButton minusBtn = new TranslateButton(TranslateButtonType.MINUS);
    TranslateButton plusBtn = new TranslateButton(TranslateButtonType.PLUS);

    public MenuStack(MainGroup mainGroup) {
        this.mainGroup = mainGroup;

        setStyle("-fx-background-color:WHITE");

        SmartHBox zoomMenu = new SmartHBox(minusBtn, plusBtn);

        SmartVBox finalMenu = new SmartVBox(zoomMenu);

        getChildren().add(finalMenu);

        addHandlers();
    }

    private void addHandlers() {
        plusBtn.setOnAction(actionEvent -> {
            mainGroup.handleEventFromMenu(MenuEvent.PLUS);
        });

        minusBtn.setOnAction(actionEvent -> {
            mainGroup.handleEventFromMenu(MenuEvent.MINUS);
        });
    }
}
