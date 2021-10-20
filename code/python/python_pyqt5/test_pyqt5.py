import  sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QToolTip, QLabel, QLineEdit
from PyQt5 import QtGui

class Janela (QMainWindow):
    def __init__(self):
        super().__init__()

        # Define os atributos da janela
        self.topo = 100
        self.esquerda = 100
        self.largura = 800
        self.altura = 600
        self.titulo = "Primeira Janela"

        # Define os atributos do botao 1
        botao1 = QPushButton("Botao 1", self)
        botao1.move(150, 200)
        botao1.resize(150, 80)
        botao1.setStyleSheet("QPushButton {background-color: #0FB328; font: bold; font-size: 20px}")
        botao1.clicked.connect(self.botao1_click)

        # Define os atributos do botao 2
        botao2 = QPushButton("Botao 2", self)
        botao2.move(350, 200)
        botao2.resize(150, 80)
        botao2.setStyleSheet("QPushButton {background-color: #0FB328; font: bold; font-size: 20px}")
        botao2.clicked.connect(self.botao2_click)

        # Define os atributos do botao texto
        botao_texto = QPushButton("Enviar Texto", self)
        botao_texto.move(550, 200)
        botao_texto.resize(150, 80)
        botao_texto.setStyleSheet("QPushButton {background-color: #0FB328; font: bold; font-size: 20px}")
        botao_texto.clicked.connect(self.mostra_texto)

        # Define os atributos do label
        #Utilizando o self para ficar vizivel fora do metodo construtor
        self.label_1 = QLabel(self)
        self.label_1.setText("Aperte algum botao")
        self.label_1.move(50, 50)
        self.label_1.resize(400, 25)
        self.label_1.setStyleSheet("QLabel {font: bold; font-size: 20px; color: 'blue'}")

        # Define os atributos do label caixa
        self.label_caixa = QLabel(self)
        self.label_caixa.setText("Digitou: ")
        self.label_caixa.move(450, 50)
        self.label_caixa.resize(400, 25)
        self.label_caixa.setStyleSheet("QLabel {font: bold; font-size: 20px; color: 'blue'}")

        # Define os atributos da imagem
        self.carro = QLabel(self)
        self.carro.move(50, 350)
        self.carro.resize(400, 200)
        self.carro.setPixmap(QtGui.QPixmap('carro1.png'))

        # Define a caixa de texto
        self.caixa_texto = QLineEdit(self)
        self.caixa_texto.move(25, 20)
        self.caixa_texto.resize(250, 25)

        # Executa o metodo carregar janela 
        self.CarregarJanela()

    def CarregarJanela(self):
        self.setGeometry(self.esquerda, self.topo, self.largura, self.altura)
        self.setWindowTitle(self.titulo)
        self.show()

    def botao1_click(self):
        self.label_1.setText("O carro 1 foi selecionado")
        self.label_1.setStyleSheet("QLabel {font: bold; font-size: 20px; color: 'green'}")
        self.carro.setPixmap(QtGui.QPixmap('carro1.png'))

    def botao2_click(self):
        self.label_1.setText("O carro 2 foi selecionado")
        self.label_1.setStyleSheet("QLabel {font: bold; font-size: 20px; color: 'red'}")
        self.carro.setPixmap(QtGui.QPixmap('carro2.png'))

    def mostra_texto(self):
        conteudo = self.caixa_texto.text()
        self.label_caixa.setText("Digitou: " + conteudo)

aplicacao = QApplication(sys.argv)
j = Janela()
sys.exit(aplicacao.exec())

# parei aqui
# https://www.youtube.com/watch?v=fwqYbmCu64w&t=1s