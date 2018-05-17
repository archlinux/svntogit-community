# $Id: PKGBUILD 69719 2012-04-23 02:56:20Z svenstaro $
# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
pkgname=cuda
pkgver=9.2.88.1
_basever=9.2.88
pkgrel=1
pkgdesc="NVIDIA's GPU programming toolkit"
arch=('x86_64')
url="http://www.nvidia.com/object/cuda_home.html"
license=('custom:NVIDIA')
depends=('gcc-libs' 'opencl-nvidia' 'nvidia-utils' 'gcc54')
replaces=('cuda-toolkit' 'cuda-sdk')
provides=('cuda-toolkit' 'cuda-sdk')
optdepends=('gdb: for cuda-gdb'
            'java-runtime: for nsight and nvvp')
options=(!strip staticlibs)
install=cuda.install
source=(https://developer.nvidia.com/compute/cuda/9.2/Prod/local_installers/cuda_${_basever}_396.26_linux
        https://developer.nvidia.com/compute/cuda/9.2/Prod/patches/1/cuda_9.2.88.1_linux
        cuda.sh
        cuda.conf
        cuda-findgllib_mk.diff)
sha512sums=('2d0d87926e11a1b21d6d3377138753df458a53ba9539d8399f9f252e0784cb41e2c63a5c724ca81ded82b9657b97fda51d812b467b0827e7d361aa2ad73b2dba'
            'd43bddb2affbc66133aab69750e8c95fd4e86bf6357c50b580301dda1819940c33e1cb442f08b25784c82d6e4de1ca6f5b474e51b1396253e4a4e6d820294ff7'
            'ce0b8df5d918ec8429da4ab8f9dee463ac04055ee5b0beeb0386b67d765a4c892d314995776a0d695cd06bcfbaf996e4904935ddc898a9d774f6bf965d989dea'
            '66bd93ecab7e1aa07218c3dd1c96e460f63ed4ac47e853ecb313c78a58e5425c8a5772f1c7f73d696bf5f93fc3e556a046a4ed955a53d900976ac525abd1f518'
            '6e9a15c73849e6400b0289ed9d6e9d3b7f100712713efcb7bbf4921f39fe671cd9fd3958e735c0da3a44f9afdd2aca94dbc63b564970a0dcacba599b570aca0f')

prepare() {
  sh cuda_${_basever}_396.26_linux --extract=${srcdir}
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
  sh "${srcdir}"/cuda_9.2.88.1_linux --silent --accept-eula --installdir="${pkgdir}/opt/cuda"

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
