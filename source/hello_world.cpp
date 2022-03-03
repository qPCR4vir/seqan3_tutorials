#include <string>
 
#include <seqan3/core/debug_stream.hpp>         // for debug_stream
#include <seqan3/io/sequence_file/input.hpp>    // for sequence_file_input
 
int main ()
{
    std::filesystem::path tmp_dir{"C:/PMS/CoV"}; // get the tmp directory
    seqan3::debug_stream <<1<< tmp_dir<<"\n";
 
    // Initialise a file input object with a FASTA file.
    seqan3::sequence_file_input file_in{tmp_dir/"allnuc0209.fasta"};
 
    // Retrieve the sequences and ids.
    for (auto & [seq, id, qual] : file_in)
    {
        if (id.starts_with("E|"))
        {   seqan3::debug_stream << "ID:     " << id << '\n';
            seqan3::debug_stream << "SEQ:    " << seq << '\n';
            seqan3::debug_stream <<  '\n';  // qual is empty for FASTA files
        }
    }
 
    return 0;
}