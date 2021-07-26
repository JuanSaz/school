## Especificaciones

Armar una librería de `I2C`. Esto va a consistir en completar las funciones que van a encontrar en el `I2C.c`:

- `I2C_Init`: Tiene que lograr configurar el I2C con 50KHz de frecuencia.
- `I2C_Wait`: Verifique los flags necesarios para asegurarse de que el periférico esté libre.
- `I2C_Start`: Fuerce la condición de start en el bus.
- `I2C_Stop`: Fuerce la condición de stop en el bus.
- `I2C_SendData`: Envíe un byte por el bus.
- `I2C_ReadDataAck`: Lea un byte del bus, lo devuelva y envíe un `ACK`.
- `I2C_ReadDataNotAck`: Lea un byte del bus, lo devuelva y no envíe un `ACK`.
- `I2C_SendSlaveAddress`: Envíe por el bus el address del slave junto con la instrucción de leer o escribir.
- `I2C_GetStatus`: Devuelva el estado de la comunicación.

Luego, hacer un `README.md` con lo siguiente:

```markdown
# I2C

Alumno: Nombre y apellido
Curso: Curso
Materia: Computadoras y Sistemas de Control
```

## Consideraciones

- Cualquier duda sobre los registros o la comunicación, pueden leer mas en la hoja de datos del `ATmega328P` en el capítulo de `2-wire Serial Interface`.

## Como entregar

- Poner el `I2C.c` y el `README.md` en una carpeta y correr lo siguiente en la terminal:

```
git init
git add README.md I2C.c
git commit -m "Initial commit"
git checkout -b aysm6/2021/i2c/lib
git push https://github.com/trq20/USERNAME.git aysm6/2021/i2c/lib
```

Donde `USERNAME` es su nombre de usuario de GitHub.
