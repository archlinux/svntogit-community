# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Co-Maintainer: Konstantin Gizdov <arch@kge.pw>
pkgname=cuda
pkgver=10.1.105
_basever=10.1.105
_driverver=418.39
pkgrel=11
pkgdesc="NVIDIA's GPU programming toolkit"
arch=('x86_64')
url="http://www.nvidia.com/object/cuda_home.html"
license=('custom:NVIDIA')
makedepends=('patchelf')
depends=('gcc-libs' 'opencl-nvidia' 'nvidia-utils' 'gcc')
replaces=('cuda-toolkit' 'cuda-sdk')
provides=('cuda-toolkit' 'cuda-sdk')
optdepends=('gdb: for cuda-gdb'
            'java-runtime=8: for nsight and nvvp')
options=(!strip staticlibs)
install=cuda.install
source=(https://developer.nvidia.com/compute/cuda/10.1/Prod/local_installers/cuda_${_basever}_${_driverver}_linux.run
        cuda.sh
        cuda.conf
        cuda-findgllib_mk.diff)
sha512sums=('07cdc053989758e4cdccaad566cae7127fa79780ad85033ea52d33cc4c43c9de08e88dd087390c58b542e51703f256859cdf51a018ee57e6a412f45fb9561622'
            'ce0b8df5d918ec8429da4ab8f9dee463ac04055ee5b0beeb0386b67d765a4c892d314995776a0d695cd06bcfbaf996e4904935ddc898a9d774f6bf965d989dea'
            '714d973bc79446f73bebe85306b3566fe25b554bcbcba2fcbe76709a3eca71fb5d183ab4da2d3b5e9326cb9cd8d13a93f6d4a005ea5a41f7ef8e6c6e81e06b5e'
            '41d6b6cad934f135eafde610d1cbd862033977fd4416a4b6abaa47709a70bab7fcf6f8377c21329084fb9db13f2a8c8c20e93c15292d7d4a6448d70a33b23f1b')

prepare() {
  sh cuda_${_basever}_${_driverver}_linux.run --target ${srcdir} --noexec

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

  # Use GCC 8
  ln -s /usr/bin/gcc "${pkgdir}/opt/cuda/bin/gcc"
  ln -s /usr/bin/g++ "${pkgdir}/opt/cuda/bin/g++"

  # Create soname variants with patchelf.
  # We have to be weird about this since for some reason the ELF SONAME is incorrect or at least partially incorrect for some libs.
  # Best we can do is copy those libs to *.so.10.1 variants, patchelf the SONAME and hope for the best.
  # Their installer used to perform this for us but now it's all manual and I think this is what we'll be stuck with for now.
  cd "${pkgdir}/opt/cuda/targets/x86_64-linux/lib"
  find "${pkgdir}"/opt/cuda/targets/x86_64-linux/lib -type l -name "*.so.10" ! -path "*stubs/*" -print0 | while read -rd '' _lib; do
    _current_soname=$(basename ${_lib})
    if [ ! -f "${_current_soname}.1" ]; then
      echo "copying ${_current_soname} to ${_current_soname}.1 version"
      cp ${_current_soname} "${_current_soname}.1"
      echo "patching ${_current_soname}.1 SONAME to match ${_current_soname}.1"
      patchelf --set-soname "${_current_soname}.1" "${_current_soname}.1"
    fi
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
}

# vim:set ts=2 sw=2 et:

