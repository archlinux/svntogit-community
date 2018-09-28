# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
pkgname=cuda
pkgver=10.0.130
_basever=10.0.130
_driverver=410.48
pkgrel=2
pkgdesc="NVIDIA's GPU programming toolkit"
arch=('x86_64')
url="http://www.nvidia.com/object/cuda_home.html"
license=('custom:NVIDIA')
depends=('gcc7-libs' 'opencl-nvidia' 'nvidia-utils' 'gcc7')
replaces=('cuda-toolkit' 'cuda-sdk')
provides=('cuda-toolkit' 'cuda-sdk')
optdepends=('gdb: for cuda-gdb'
            'java-runtime: for nsight and nvvp')
options=(!strip staticlibs)
install=cuda.install
source=(https://developer.nvidia.com/compute/cuda/10.0/Prod/local_installers/cuda_${_basever}_${_driverver}_linux
        cuda.sh
        cuda.conf
        cuda-findgllib_mk.diff)
sha512sums=('409ea4cc6aa0fe7063450e77c3b67b9b41aab1bbe556db673fb1a80610b20bd52e2020bf94034a92ab68c721d3d5739500bae4bd7a3558b2d8e73730a3b4ea25'
            'ce0b8df5d918ec8429da4ab8f9dee463ac04055ee5b0beeb0386b67d765a4c892d314995776a0d695cd06bcfbaf996e4904935ddc898a9d774f6bf965d989dea'
            '0f1f5bed19f9eaf66b53e32d2e163a40d03e11565b3d5d9f5220b6904bb510fd9548e0dd8a33ee84e729845333158f9fed078584e80a8361ca434b1410624473'
            '41d6b6cad934f135eafde610d1cbd862033977fd4416a4b6abaa47709a70bab7fcf6f8377c21329084fb9db13f2a8c8c20e93c15292d7d4a6448d70a33b23f1b')

prepare() {
  sh cuda_${_basever}_${_driverver}_linux --extract=${srcdir}
  ./cuda-*.run --noexec --keep
  ./cuda-samples*.run --noexec --keep

  # path hacks

  # 1rd sed line: sets right path to install man files
  # 2rd sed line: hack to lie installer, now detect launch script by root
  # 3rd sed line: sets right path in .desktop files and other .desktop stuff (warnings by desktop-file-validate)
  sed -e "s|/usr/share|${srcdir}/../pkg/${pkgname}/usr/share|g" \
      -e 's|can_add_for_all_users;|1;|g' \
      -e 's|=\\"$prefix\\\"|=/opt/cuda|g' -e 's|Terminal=No|Terminal=false|g' -e 's|ParallelComputing|ParallelComputing;|g' \
      -i pkg/install-linux.pl

  # set right path in Samples Makefiles
  sed 's|\$cudaprefix\\|\\/opt\\/cuda\\|g' -i pkg/install-sdk-linux.pl

  # use python2
  find pkg -name '*.py' | xargs sed -i -e 's|env python|env python2|g' -e 's|bin/python|bin/python2|g'

  # Fix up samples tht use findgllib_mk
  for f in pkg/samples/*/*/findgllib.mk; do
    patch $f cuda-findgllib_mk.diff
  done
}

package() {
  cd pkg
  export PERL5LIB=.
  perl install-linux.pl -prefix="${pkgdir}/opt/cuda" -noprompt
  perl install-sdk-linux.pl -cudaprefix="${pkgdir}/opt/cuda" -prefix="${pkgdir}/opt/cuda/samples" -noprompt

  # Needs gcc7
  ln -s /usr/bin/gcc-7 "${pkgdir}/opt/cuda/bin/gcc"
  ln -s /usr/bin/g++-7 "${pkgdir}/opt/cuda/bin/g++"

  # Install profile and ld.so.config files
  install -Dm755 "${srcdir}/cuda.sh" "${pkgdir}/etc/profile.d/cuda.sh"
  install -Dm644 "${srcdir}/cuda.conf" "${pkgdir}/etc/ld.so.conf.d/cuda.conf"

  mkdir -p "${pkgdir}/usr/share/licenses/${pkgname}"
  ln -s /opt/cuda/doc/pdf/EULA.pdf "${pkgdir}/usr/share/licenses/${pkgname}/EULA.pdf"

  # Remove redundant man and samples
  rm -fr "${pkgdir}/opt/cuda/cuda-samples"
  rm -fr "${pkgdir}/usr/share/man/man3"

  # Remove included copy of java and link to system java
  rm -fr  "${pkgdir}/opt/cuda/jre"
  sed 's|../jre/bin/java|/usr/bin/java|g' \
    -i "${pkgdir}/opt/cuda/libnsight/nsight.ini" \
    -i "${pkgdir}/opt/cuda/libnvvp/nvvp.ini"

  # Remove unused files
  rm -fr "${pkgdir}/opt/cuda/"{bin,samples}"/.uninstall_manifest_do_not_delete.txt"
  rm -fr "${pkgdir}/opt/cuda/samples/uninstall_cuda_samples"*.pl
  rm -fr "${pkgdir}/opt/cuda/bin/cuda-install-samples"*.sh
  rm -fr "${pkgdir}/opt/cuda/bin/uninstall_cuda_toolkit"*.pl
}
