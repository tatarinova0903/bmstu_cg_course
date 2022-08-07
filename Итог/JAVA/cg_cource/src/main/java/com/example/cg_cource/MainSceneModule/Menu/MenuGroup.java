package com.example.cg_cource.MainSceneModule.Menu;

import com.example.cg_cource.Helpers.MenuEvent;
import com.example.cg_cource.MainSceneModule.MainGroup;
import com.example.cg_cource.MainSceneModule.MainScene;
import com.example.cg_cource.MainSceneModule.Room.RoomGroup;
import com.example.cg_cource.Views.SmartHBox;
import com.example.cg_cource.Views.SmartVBox;
import com.example.cg_cource.Views.TranslateButton;
import com.example.cg_cource.Views.TranslateButtonType;
import javafx.scene.layout.StackPane;

public class MenuGroup extends StackPane {
    MainGroup mainGroup;

    TranslateButton minusBtn = new TranslateButton(TranslateButtonType.MINUS);
    TranslateButton plusBtn = new TranslateButton(TranslateButtonType.PLUS);

    public MenuGroup(MainGroup mainGroup) {
        this.mainGroup = mainGroup;
        setLayoutX(-350);
        setLayoutY(-100);

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
