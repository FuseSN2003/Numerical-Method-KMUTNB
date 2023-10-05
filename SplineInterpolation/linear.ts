const linear = (pointX: number[], pointY: number[], targetX: number) => {
  for(let i = 0; i < pointX.length - 1; i++) {
    if(pointX[i] <= targetX && pointX[i+1] >= targetX) {
      return pointY[i] + ((pointY[i + 1] - pointY[i]) / (pointX[i + 1] - pointX[i])) * (targetX - pointX[i])
    }
  }
}

let pointX: number[] = [2, 4, 6, 8, 10]
let pointY: number[] = [9.5, 8.0, 10.5, 39.5, 72.5]
let targetX: number = 4.5

console.log(linear(pointX, pointY, targetX))