
### Aula 04 - Operadores Lógicos e Comandos SWITCH, CASE e DEFAULT

	- não -> !
	- E ->   &&
	- OU ->  ||

### Operador "NÃO"
|valor|Resultado|
|-----|-----|
|0|1|
|1|0|

|valor|Resultado|
|-----|-----|
|false|true|
|true|false|

|valor|Resultado|
|-----|-----|
|LOW|HIGH|
|HIGH|LOW|

### Operador "E"
	valor_esquerda && valor_direita

|valor_esquerda|valor_direita|Resultado|
|--|--|--|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

|valor_esquerda|valor_direita|Resultado|
|--|--|--|
|false|false|false|
|false|true|false|
|true|false|false|
|true|true|true|

|valor_esquerda|valor_direita|Resultado|
|--|--|--|
|LOW|LOW|LOW|
|LOW|HIGH|LOW|
|HIGH|LOW|LOW|
|HIGH|HIGH|HIGH|

### Operador "OU"
	valor_esquerda || valor_direita
|valor_esquerda|valor_direita|Resultado|
|--|--|--|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|1|

|valor_esquerda|valor_direita|Resultado|
|--|--|--|
|false|false|false|
|false|true|true|
|true|false|true|
|true|true|true|

|valor_esquerda|valor_direita|Resultado|
|--|--|--|
|LOW|LOW|LOW|
|LOW|HIGH|HIGH|
|HIGH|LOW|HIGH|
|HIGH|HIGH|HIGH|

### Operadores de Comparação
	== 	valor_esquerda == valor_direita
	!= 	valor_esquerda != valor_direita
	> 	valor_esquerda > valor_direita
	< 	valor_esquerda < valor_direita
	>= 	valor_esquerda >= valor_direita
	<= 	valor_esquerda <= valor_direita

	


