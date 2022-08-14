package com.example.cg_cource.MenuModule;

import com.example.cg_cource.Helpers.MenuEvent;
import com.example.cg_cource.MainSceneModule.MainGroup;
import com.example.cg_cource.Views.SmartHBox;
import com.example.cg_cource.Views.SmartVBox;
import com.example.cg_cource.Views.TranslateButton;
import javafx.scene.layout.StackPane;

public class MenuStack extends StackPane {
    MainGroup mainGroup;

    TranslateButton minusBtn = new TranslateButton(MenuEvent.MINUS);
    TranslateButton plusBtn = new TranslateButton(MenuEvent.PLUS);
    TranslateButton rotateLeft = new TranslateButton(MenuEvent.ROTATE_LEFT);
    TranslateButton rotateRight = new TranslateButton(MenuEvent.ROTATE_RIGHT);
    TranslateButton rotateUp = new TranslateButton(MenuEvent.ROTATE_UP);
    TranslateButton rotateDown = new TranslateButton(MenuEvent.ROTATE_DOWN);

    public MenuStack(MainGroup mainGroup) {
        this.mainGroup = mainGroup;

        setStyle("-fx-background-color:WHITE");

        SmartHBox zoomMenu = new SmartHBox(minusBtn, plusBtn);
        SmartHBox rotateMenu = new SmartHBox(rotateLeft, rotateRight, rotateUp, rotateDown);

        SmartVBox finalMenu = new SmartVBox(zoomMenu, rotateMenu);

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

        rotateLeft.setOnAction(actionEvent -> {
            mainGroup.handleEventFromMenu(MenuEvent.ROTATE_LEFT);
        });

        rotateRight.setOnAction(actionEvent -> {
            mainGroup.handleEventFromMenu(MenuEvent.ROTATE_RIGHT);
        });

        rotateUp.setOnAction(actionEvent -> {
            mainGroup.handleEventFromMenu(MenuEvent.ROTATE_UP);
        });

        rotateDown.setOnAction(actionEvent -> {
            mainGroup.handleEventFromMenu(MenuEvent.ROTATE_DOWN);
        });
    }
}
