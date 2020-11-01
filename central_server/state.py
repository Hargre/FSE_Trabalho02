class HouseState:
    def __init__(self):
        self.temperature = 0
        self.humidity = 0
        self.lamp01 = 0
        self.lamp02 = 0
        self.lamp03 = 0
        self.lamp04 = 0
        self.air01 = 0
        self.air02 = 0
        self.presence01 = 0
        self.presence02 = 0
        self.open01 = 0
        self.open02 = 0
        self.open03 = 0
        self.open04 = 0
        self.open05 = 0
        self.open06 = 0

    def __str__(self):
        return "Temperatura: %.2f Umidade %.2f\n\
            Lâmpadas:\nCozinha: %d\nSala: %d\nQuarto 01: %d\nQuarto 02: %d\n\
            Ares-Condicionados:\nQuarto 01: %d\nQuarto 02: %d\n\
            Presença em Cômodos:\nSala: %d\nCozinha: %d\n\
            Portas e Janelas Abertas:\n Porta Cozinha: %d\nJanela Cozinha: %d\n\
            Porta Sala: %d\nJanela Sala: %d\n\
            Janela Quarto 01: %d\nJanela Quarto 02: %d\n" % (
                self.temperature, self.humidity,
                self.lamp01, self.lamp02, self.lamp03, self.lamp04,
                self.air01, self.air02,
                self.presence01, self.presence02,
                self.open01, self.open02, self.open03, self.open04, self.open05, self.open06
            )


    def set_state(self, data):
        data = data.split(',')
        self.temperature = float(data[0])
        self.humidity = float(data[1])
        self.lamp01 = int(data[2])
        self.lamp02 = int(data[3])
        self.lamp03 = int(data[4])
        self.lamp04 = int(data[5])
        self.air01 = int(data[6])
        self.air02 = int(data[7])
        self.presence01 = int(data[8])
        self.presence02 = int(data[9])
        self.open01 = int(data[10])
        self.open02 = int(data[11])
        self.open03 = int(data[12])
        self.open04 = int(data[13])
        self.open05 = int(data[14])
        self.open06 = int(data[15])
