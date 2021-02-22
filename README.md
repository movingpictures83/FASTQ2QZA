# FASTQ2QZA
# Language: C++
# Input: TXT
# Output: QZA
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Qiime 2 2020.11, Conda 4.9.2

PluMA plugin to convert multiple FASTQ files into a single QZA file for Qiime 2 (Bolyen et al, 2019).

Output file will be in QZA format.  The input file is a TXT file of tab-delimited keyword-value pairs:

manifest: Manifest file containing sequence names and absolute pathnames for forward and reverse sequence files
format: Format used for manifest (i.e. PairedEndFastqManifestPhred33V2)


