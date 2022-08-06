package com.example.cg_cource;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.*;
import javafx.scene.text.Text;

public class MainController extends AnchorPane {
    private final Text currMousePositionLabel = new Text();
    private final Button plusBtn = new Button("+");
    private final Button minusBtn = new Button("-");
    private final Button cancelBtn = new Button("Отменить");
    private final ToggleGroup toggleSetGroup = new ToggleGroup();
    private final ToggleButton firstSetBtn = new ToggleButton("1 множество");
    private final ToggleButton secondSetBtn = new ToggleButton("2 множество");
    private final ToggleGroup toggleActionGroup = new ToggleGroup();
    private final ToggleButton inputSetBtn = new ToggleButton("Ввести");
    private final ToggleButton editBtn = new ToggleButton("Редактировать");
    private final Button clearBtn = new Button("Очистить");
    private final Button calculateBtn = new Button("Вычислить");
    private final Button addToSetBtn = new Button("Добавить");
    private final Text coordXLabel = new Text("X:");
    private final TextField coordXField = new TextField();
    private final Text coordYLabel = new Text("Y:");
    private final TextField coordYField = new TextField();
    private final ResizableCanvas canvas = new ResizableCanvas(this);

    public MainController() {
        HBox setBox = new HBox(firstSetBtn, secondSetBtn);
        setBox.setAlignment(Pos.CENTER);
        setBox.setSpacing(0);
        setBox.setStyle("-fx-border-color: #ffffff;");
        setBox.getChildren().forEach(element -> {
            element.setFocusTraversable(false);
        });

        HBox actionBox = new HBox(inputSetBtn, editBtn);
        actionBox.setAlignment(Pos.CENTER);
        actionBox.setSpacing(0);
        actionBox.getChildren().forEach(element -> {
            element.setFocusTraversable(false);
        });

        firstSetBtn.setToggleGroup(toggleSetGroup);
        secondSetBtn.setToggleGroup(toggleSetGroup);
        inputSetBtn.setToggleGroup(toggleActionGroup);
        editBtn.setToggleGroup(toggleActionGroup);
        HBox mainMenu = new HBox(
                plusBtn,
                minusBtn,
                cancelBtn,
                actionBox,
                setBox,
                calculateBtn
        );
        mainMenu.setAlignment(Pos.CENTER);
        mainMenu.setSpacing(10);
        mainMenu.getChildren().forEach(element -> {
            element.setFocusTraversable(false);
        });

        coordXField.setMaxWidth(60);
        coordYField.setMaxWidth(60);
        HBox editMenu = new HBox(
                coordXLabel,
                coordXField,
                coordYLabel,
                coordYField,
                addToSetBtn,
                clearBtn
        );
        editMenu.setAlignment(Pos.CENTER);
        editMenu.setSpacing(5);
        editMenu.getChildren().forEach(element -> {
            element.setFocusTraversable(false);
        });

        VBox main = new VBox(mainMenu, editMenu, canvas);
        main.setSpacing(5);
        this.getChildren().add(main);

        canvas.widthProperty().bind(this.widthProperty());
        canvas.heightProperty().bind(this.heightProperty());

        addHandlers();
    }

    void keyboardDidTap(KeyEvent keyEvent) {

    }

    private void addHandlers() {

    }
}