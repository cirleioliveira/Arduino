
# Aula 05.A - AULA DE APOIO - Programação Orientada a Objetos
	int temperatura = 30;
	analog write(temperatura);

## ORIENTADO A OBJETO

# Nascimento de uma estutura (nova)

	struct tempo {
		int temperaura;
		int umidade;
	};


# NASCIMENTO DE UMA VARIAVEL ESTRUTURADA 

	tempo leitura1;

### USO DE UMA VARIAVEL ESTRUTURADA (ATRIBUTO)

	leitura1.temperatura = 30;

### USO DE UMA VARIAVEL ESTRUTURADA (LER)
	analog write(leitura1.temperatura);

# NASCIMENTO DE UMA CLASSE
Uma classe para se ter o objto é a mesmo coisa que ter uma estrutura (struct), esse treço abaixo é um exemplo de criar uma classe, fica no inicio.

	class SensorTempo {
		SensorTempo();      // metodo que funciona como função
		void LerSensor();   // metodo
		void LimpaDados();  // metodo
		int temperaura;     // propriedade
		int umidade;        // propriedade esta detro de um objeto
	};

### Implementação de um método
	void SensorTempo::LerSensor(){         // os dois ponto (::) na frente precisa colocar o nome da classe 
		temperatura = analogRead(A0);
		umidade = analogRead(A1);
	}

### Implementação de um método construtor
	SensorTempo::SensorTempo(){
		temperatura = 9;
		umidade = 9;
	}

# Nascimento de um objeto (instanciação)
	SensorTempo sensor1();  //criar objeto

### Uso de um objeto (Execução de um metodo)
	sensor1.LerSensor();

### Leitura de uma propriedade
	analogWrite( sensro1.temperatura );

## Encapsulamento  
O encapsulamento é para protejer o objeto

	class SensorTempo {
		public:
			SensorTempo();      
			void LerSensor();   
			void LimpaDados();  
		private:
			void LimpaDados():
			int temperaura;     
			int umidade;        
	};

Metodo publico

	int SensorTempo:: RetornaTemperatura(){
		retun temperatura;
	}






	


