const path = require('path');
const outputDir = path.join(__dirname, "build/");

module.exports = {
  entry: './src/Demo.bs.js',
  mode: 'development',
  output: {
    path: outputDir,
    publicPath: outputDir,
    filename: 'Index.js',
  },
  module: {
    rules: [
      {
        test: /\.(png|svg|jpg|gif)$/,
        use: [ 'file-loader' ]
      }
    ]
  }
};
