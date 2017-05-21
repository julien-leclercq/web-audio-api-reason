open WebAudioApiTypes;

module AudioBufferSourceNodeRe: {
  include AudioNodeRe.AudioNodeBase;

  let get_buffer : t => array_buffer;

  let set_buffer : t => array_buffer => t;

  let create_audio_buffer_source_node : audio_context => t;

};
