module type AudioNodeBase = {

  type t;

  let get_context : t => audio_context;

  let get_number_of_inputs : t => int;

  let get_number_of_outputs : t => int;

  let get_channel_count : t => int;

  let set_channel_count : t => int => t;

};

