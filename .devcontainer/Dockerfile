FROM espressif/idf:v5.4.1

RUN apt-get update && apt-get install -y clang-format vim-tiny
RUN echo "source /opt/esp/idf/export.sh > /dev/null 2>&1" >> ~/.bashrc
RUN echo "set -o vi" >> ~/.bashrc

# Set vi as the default editor for Git
RUN git config --global core.editor vi

ENTRYPOINT [ "/opt/esp/entrypoint.sh" ]

CMD ["/bin/bash"]
