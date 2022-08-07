package com.example.cg_cource.MainSceneModule.Menu;

import com.example.cg_cource.Views.SmartHBox;
import com.example.cg_cource.Views.SmartVBox;
import com.example.cg_cource.Views.TranslateButton;
import com.example.cg_cource.Views.TranslateButtonType;
import javafx.scene.layout.StackPane;

public class MenuGroup extends StackPane {
    public MenuGroup() {
        setLayoutX(-350);
        setLayoutY(-100);

        TranslateButton minusBtn = new TranslateButton(TranslateButtonType.MINUS);
        TranslateButton plusBtn = new TranslateButton(TranslateButtonType.PLUS);

        SmartHBox zoomMenu = new SmartHBox(minusBtn, plusBtn);

        SmartVBox finalMenu = new SmartVBox(zoomMenu);

        getChildren().add(finalMenu);
    }
}
