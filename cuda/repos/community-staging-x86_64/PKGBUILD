# $Id: PKGBUILD 69719 2012-04-23 02:56:20Z svenstaro $
# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
pkgname=cuda
pkgver=9.1.85.3
_basever=9.1.85
pkgrel=5
pkgdesc="NVIDIA's GPU programming toolkit"
arch=('x86_64')
url="http://www.nvidia.com/object/cuda_home.html"
license=('custom:NVIDIA')
depends=('gcc-libs' 'opencl-nvidia' 'gcc54' 'nvidia-utils')
replaces=('cuda-toolkit' 'cuda-sdk')
provides=('cuda-toolkit' 'cuda-sdk')
optdepends=('gdb: for cuda-gdb'
            'java-runtime: for nsight and nvvp')
options=(!strip staticlibs)
install=cuda.install
source=(https://developer.nvidia.com/compute/cuda/9.1/Prod/local_installers/cuda_${_basever}_387.26_linux
        https://developer.nvidia.com/compute/cuda/9.1/Prod/patches/1/cuda_9.1.85.1_linux
        https://developer.nvidia.com/compute/cuda/9.1/Prod/patches/2/cuda_9.1.85.2_linux
        https://developer.nvidia.com/compute/cuda/9.1/Prod/patches/3/cuda_9.1.85.3_linux
        cuda.sh
        cuda.conf
        cuda-findgllib_mk.diff)
sha512sums=('492a5fa58fc93ac718ca093f24bb5e74dd2586338c42f2e11e328c7f16756e3511a1c555b12cb1990bb782d0d1600976f4c9e5b3d4857e371b0431daf06b2827'
            'a29099ffad3470b8fe3a64c2ad675fd7950bd63dcf722dd19083c7daba55be90755456b937347ae3323b50d797a138f81daefddfd37228a6f75b2341dbd861fa'
            '62644aa8219ff5ce7428033e279ebc05d96596c3c2b9d27f783aff90f41e38e0341578cc1b33e8d6d64c59a544c3e6174e77c5d046de9b12261d1f7e73b259c5'
            'dcafdd55cbc6d9063f6dc2001c0365f1c1279254378d4d0231039be78b9dec5d6078b3500fa49457fbbf0fad8a17ef0d18c7fa21551b80dc99a16f2ae2a4110a'
            'ce0b8df5d918ec8429da4ab8f9dee463ac04055ee5b0beeb0386b67d765a4c892d314995776a0d695cd06bcfbaf996e4904935ddc898a9d774f6bf965d989dea'
            '66bd93ecab7e1aa07218c3dd1c96e460f63ed4ac47e853ecb313c78a58e5425c8a5772f1c7f73d696bf5f93fc3e556a046a4ed955a53d900976ac525abd1f518'
            '6e9a15c73849e6400b0289ed9d6e9d3b7f100712713efcb7bbf4921f39fe671cd9fd3958e735c0da3a44f9afdd2aca94dbc63b564970a0dcacba599b570aca0f')

prepare() {
  sh cuda_${_basever}_387.26_linux --extract=${srcdir}
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
  sh "${srcdir}"/cuda_9.1.85.1_linux --silent --accept-eula --installdir="${pkgdir}/opt/cuda"
  sh "${srcdir}"/cuda_9.1.85.2_linux --silent --accept-eula --installdir="${pkgdir}/opt/cuda"
  sh "${srcdir}"/cuda_9.1.85.3_linux --silent --accept-eula --installdir="${pkgdir}/opt/cuda"

  # Hack we need because of glibc 2.26 (https://bugs.archlinux.org/task/55580)
  # without which we couldn't compile anything at all.
  # Super dirty hack. I really hope it doesn't break other stuff!
  # Hopefully we can remove this for later version of cuda.
  sed -i "1 i#define _BITS_FLOATN_H" "${pkgdir}/opt/cuda/include/host_defines.h"

  # Needs gcc5
  ln -s /usr/bin/gcc-5 "${pkgdir}/opt/cuda/bin/gcc"
  ln -s /usr/bin/g++-5 "${pkgdir}/opt/cuda/bin/g++"

  # Install profile and ld.so.config files
  install -Dm755 "${srcdir}/cuda.sh" "${pkgdir}/etc/profile.d/cuda.sh"
  install -Dm644 "${srcdir}/cuda.conf" "${pkgdir}/etc/ld.so.conf.d/cuda.conf"

  mkdir -p "${pkgdir}/usr/share/licenses/${pkgname}"
  ln -s /opt/cuda/doc/pdf/EULA.pdf "${pkgdir}/usr/share/licenses/${pkgname}/EULA.pdf"

  # Remove redundant man and samples
  rm -fr "${pkgdir}/opt/cuda/doc/man"
  rm -fr "${pkgdir}/opt/cuda/cuda-samples"
  rm -fr "${pkgdir}/usr/share/man/man3/deprecated.3"*

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
