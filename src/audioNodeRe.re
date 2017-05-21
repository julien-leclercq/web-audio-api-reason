open WebAudioApiTypes;

module type AudioNodeType = {
  type t;
};

/* module signature for AudioNode childs */
module MakeAudioNode = fun (N: AudioNodeType) => {

  external get_context : N.t => audio_context = "" [@@bs.get];
  external get_number_of_inputs : N.t => int = "numberOfInputs" [@@bs.get];
  external get_number_of_outputs : N.t => int = "numberOfOutputs" [@@bs.get];
  external get_channel_count : N.t => int = "channelCount" [@@bs.get];
  external _set_channel_count : N.t => int => unit = "channel_count" [@@bs.set];

  let set_channel_count node channel_number => {
    _set_channel_count node channel_number;
    node;
  };
};


module type AudioNodeBase = {

  type t;

  let get_context : t => audio_context;

  let get_number_of_inputs : t => int;

  let get_number_of_outputs : t => int;

  let get_channel_count : t => int;

  let set_channel_count : t => int => t;

};

