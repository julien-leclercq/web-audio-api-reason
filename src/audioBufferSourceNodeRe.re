open WebAudioApiTypes;

module AudioBufferSource= {
  type t = audio_buffer_source_node;

  external _create_audio_buffer_source_node : audio_context => t = "AudioBufferSourceNode" [@@bs.new];
  external _set_buffer : t => array_buffer => unit = "buffer" [@@bs.set];
  external _get_buffer : t => array_buffer = "buffer" [@@bs.get];

  let get_buffer source_node => _get_buffer source_node;
  let set_buffer source_node buffer => {
    _set_buffer source_node buffer;
    source_node;
  };

  let create_audio_buffer_source_node = _create_audio_buffer_source_node;
};

module AudioBufferSourceNodeRe = {
  include AudioBufferSource;
  include AudioNodeRe.MakeAudioNode(AudioBufferSource);
};
