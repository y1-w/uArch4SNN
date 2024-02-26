# snn-coprocessor

Spiking Neural Network (SNN) coprocessor for convolutional and fully-connected layers

The implementation of the SNN coprocessor relies on the High-level synthesis (HLS) design files provided here. There are two sets of files for spiking fully connected neural networks (*hls_fcsnn_v42*) and spiking convolutional neural networks (*hls_csnn_v7*). 

The instruction set implemented in *hls_fcsnn_v42* is shown in the table below. 
![isa](https://github.com/yimin-github/snn-coprocessor/assets/91878760/581820db-e872-4176-b91d-e9b7eaea28d1)

The full implementation of the *hls_fcsnn_v42* in Vivado 2018.3 is shown in the figure below. 
![vivadoblk2](https://github.com/yimin-github/snn-coprocessor/assets/91878760/5413ed1d-d470-445c-ba6b-39eac4a1809f)
