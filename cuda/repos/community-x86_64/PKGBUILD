# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Maintainer: Konstantin Gizdov <arch@kge.pw>
pkgname=cuda
pkgver=10.2.89
_driverver=440.33.01
pkgrel=1
pkgdesc="NVIDIA's GPU programming toolkit"
arch=('x86_64')
url="https://developer.nvidia.com/cuda-zone"
license=('custom:NVIDIA')
depends=('gcc8-libs'  'gcc8' 'opencl-nvidia' 'nvidia-utils')
replaces=('cuda-toolkit' 'cuda-sdk')
provides=('cuda-toolkit' 'cuda-sdk')
optdepends=('gdb: for cuda-gdb'
            'java-runtime=8: for nsight and nvvp')
options=(!strip staticlibs)
install=cuda.install
source=(http://developer.download.nvidia.com/compute/cuda/10.2/Prod/local_installers/cuda_${pkgver}_${_driverver}_linux.run
        cuda.sh
        cuda.conf
        cuda-findgllib_mk.diff)
sha512sums=('ad8da539ff5df7caf411d1e497ff3d6978cfa8a1fd9150fa4846089e92a604ea56be8631f3efdfe7229a655b8d2d28e6edb32f5731530a77d6f00241cc7aab6e'
            'b3691913027b8390161c7412d87a905712d90434cc82027a52f203f8ae3dda755738f734f8190277471e4541d685b524568ad03af58d4b7ebad346eee11c10e4'
            '714d973bc79446f73bebe85306b3566fe25b554bcbcba2fcbe76709a3eca71fb5d183ab4da2d3b5e9326cb9cd8d13a93f6d4a005ea5a41f7ef8e6c6e81e06b5e'
            '41d6b6cad934f135eafde610d1cbd862033977fd4416a4b6abaa47709a70bab7fcf6f8377c21329084fb9db13f2a8c8c20e93c15292d7d4a6448d70a33b23f1b')

prepare() {
  sh cuda_${pkgver}_${_driverver}_linux.run --target "${srcdir}" --noexec

  # Fix up samples tht use findgllib_mk
  for f in builds/cuda-samples/*/*/findgllib.mk; do
    patch $f cuda-findgllib_mk.diff
  done
}

package() {
  mkdir -p "${pkgdir}/opt/"

  cd "${srcdir}/builds"
  cp -r cuda-toolkit "${pkgdir}/opt/cuda"
  cp -r cublas/include/* "${pkgdir}/opt/cuda/include/"
  cp -r cublas/lib64/* "${pkgdir}/opt/cuda/lib64/"
  cp -r cuda-samples "${pkgdir}/opt/cuda/samples"
  ln -s /opt/cuda/targets/x86_64-linux/lib "${pkgdir}/opt/cuda/lib"
  ln -s /opt/cuda/nvvm/lib64 "${pkgdir}/opt/cuda/nvvm/lib"

  # Define compilers for CUDA to use.
  # This allows us to use older versions of GCC if we have to.
  ln -s /usr/bin/gcc-8 "${pkgdir}/opt/cuda/bin/gcc"
  ln -s /usr/bin/g++-8 "${pkgdir}/opt/cuda/bin/g++"

  # Create soname links.
  # We have to be weird about this since for some reason the ELF SONAME is incorrect or at least partially incorrect for some libs.
  # Best we can do is create all symlinks and hope for the best.
  # Their installer used to perform this for us but now it's all manual and I think this is what we'll be stuck with for now.
  find cuda-toolkit/targets -type f -name '*.so*' ! -path '*stubs/*' -print0 | while read -rd $'\0' _lib; do
    _base=${_lib%.so.*}
    _current_soname=$(basename ${_lib%.*})
    while [[ $_current_soname != $(basename $_base) ]]; do
      ln -sf ${_lib##*/} ${pkgdir}/opt/cuda/lib64/$_current_soname
      _current_soname=${_current_soname%.*}
    done
  done

  # Install profile and ld.so.config files
  install -Dm755 "${srcdir}/cuda.sh" "${pkgdir}/etc/profile.d/cuda.sh"
  install -Dm644 "${srcdir}/cuda.conf" "${pkgdir}/etc/ld.so.conf.d/cuda.conf"

  mkdir -p "${pkgdir}/usr/share/licenses/${pkgname}"
  ln -s /opt/cuda/doc/pdf/EULA.pdf "${pkgdir}/usr/share/licenses/${pkgname}/EULA.pdf"

  # Remove included copy of java and link to system java 8
  rm -fr  "${pkgdir}/opt/cuda/jre"
  sed 's|../jre/bin/java|/usr/lib/jvm/java-8-openjdk/jre/bin/java|g' \
    -i "${pkgdir}/opt/cuda/libnsight/nsight.ini" \
    -i "${pkgdir}/opt/cuda/libnvvp/nvvp.ini"

  # Allow GCC 9 to work
  sed -i "/.*unsupported GNU version.*/d" "${pkgdir}"/opt/cuda/targets/x86_64-linux/include/crt/host_config.h

  # Fix Makefile paths to CUDA
  for f in $(find "$pkgdir"/opt/cuda -name Makefile); do
    sed -i "s|/usr/local/cuda|/opt/cuda|g" "$f"
  done
}

# vim:set ts=2 sw=2 et:

