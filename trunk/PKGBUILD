# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
pkgname=cuda
pkgver=10.1.105
_basever=10.1.105
_driverver=418.39
pkgrel=1
pkgdesc="NVIDIA's GPU programming toolkit"
arch=('x86_64')
url="http://www.nvidia.com/object/cuda_home.html"
license=('custom:NVIDIA')
depends=('gcc-libs' 'opencl-nvidia' 'nvidia-utils')
replaces=('cuda-toolkit' 'cuda-sdk')
provides=('cuda-toolkit' 'cuda-sdk')
optdepends=('gdb: for cuda-gdb'
            'java-runtime: for nsight and nvvp')
options=(!strip staticlibs)
install=cuda.install
source=(https://developer.nvidia.com/compute/cuda/10.1/Prod/local_installers/cuda_${_basever}_${_driverver}_linux.run
        cuda.sh
        cuda.conf
        cuda-findgllib_mk.diff)
sha512sums=('07cdc053989758e4cdccaad566cae7127fa79780ad85033ea52d33cc4c43c9de08e88dd087390c58b542e51703f256859cdf51a018ee57e6a412f45fb9561622'
            'ce0b8df5d918ec8429da4ab8f9dee463ac04055ee5b0beeb0386b67d765a4c892d314995776a0d695cd06bcfbaf996e4904935ddc898a9d774f6bf965d989dea'
            '268effce192d72d51658c1c337517f47e731fc820cdf6918cfc31e787e286a6afe42914650050e7df18a5f14beebaa1b23cc3cb0b459e8c794b74226bd2d5701'
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

  cd builds
  cp -r cublas "${pkgdir}/opt/cublas"
  ln -s lib64 "${pkgdir}/opt/cublas/lib"

  cp -r cuda-samples "${pkgdir}/opt/cuda-samples"

  cp -r cuda-toolkit "${pkgdir}/opt/cuda"
  ln -s lib "${pkgdir}/opt/cuda/lib64"
  ln -s lib "${pkgdir}/opt/cuda/nvvm/lib64"

  # Install profile and ld.so.config files
  install -Dm755 "${srcdir}/cuda.sh" "${pkgdir}/etc/profile.d/cuda.sh"
  install -Dm644 "${srcdir}/cuda.conf" "${pkgdir}/etc/ld.so.conf.d/cuda.conf"

  mkdir -p "${pkgdir}/usr/share/licenses/${pkgname}"
  ln -s /opt/cuda/doc/pdf/EULA.pdf "${pkgdir}/usr/share/licenses/${pkgname}/EULA.pdf"

  # Remove included copy of java and link to system java
  rm -fr  "${pkgdir}/opt/cuda/jre"
  sed 's|../jre/bin/java|/usr/bin/java|g' \
    -i "${pkgdir}/opt/cuda/libnsight/nsight.ini" \
    -i "${pkgdir}/opt/cuda/libnvvp/nvvp.ini"
}
