# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Maintainer: Konstantin Gizdov <arch@kge.pw>
pkgname=cuda
pkgver=11.0.2
_driverver=450.51.05
pkgrel=1
pkgdesc="NVIDIA's GPU programming toolkit"
arch=('x86_64')
url="https://developer.nvidia.com/cuda-zone"
license=('custom:NVIDIA')
depends=('gcc9-libs'  'gcc9' 'opencl-nvidia' 'nvidia-utils')
replaces=('cuda-toolkit' 'cuda-sdk')
provides=('cuda-toolkit' 'cuda-sdk')
optdepends=('gdb: for cuda-gdb'
            'java-runtime=8: for nsight and nvvp')
options=(!strip staticlibs)
install=cuda.install
source=(http://developer.download.nvidia.com/compute/cuda/${pkgver}/local_installers/cuda_${pkgver}_${_driverver}_linux.run
        cuda.sh
        cuda.conf
        cuda-findgllib_mk.diff
        *.pc)
sha512sums=('b20853fe7106c50b05419879172cbbfc3bb3deb381acbd8db3e6363e9963d4c944002da77014787cce3fe5151064c70436311892b6335579aa5b765cc6191d16'
            'b3691913027b8390161c7412d87a905712d90434cc82027a52f203f8ae3dda755738f734f8190277471e4541d685b524568ad03af58d4b7ebad346eee11c10e4'
            '714d973bc79446f73bebe85306b3566fe25b554bcbcba2fcbe76709a3eca71fb5d183ab4da2d3b5e9326cb9cd8d13a93f6d4a005ea5a41f7ef8e6c6e81e06b5e'
            '41d6b6cad934f135eafde610d1cbd862033977fd4416a4b6abaa47709a70bab7fcf6f8377c21329084fb9db13f2a8c8c20e93c15292d7d4a6448d70a33b23f1b'
            '54f63b7f55948341e7ef17c6d2175bdf4cb92105330b08579b401f37c95692fd5b185d9cde498ce39ec2687295c2b5ff6e5c4c8e36c861d781fef9db3de752be'
            '08dbc847cd239e6eeae0a97b02b24720d003105eae3596cc811ca5e6467ca5005dd83f86311eb662868686eb4415af1b39b01bb2fe799211fe0979e39efd1245'
            'de28a65c39bc9079b0c38656dc278bc89820b7531fec60d97d784711543f0cb3405d52e43caae212f0fc83a05d1d1385137d31a93c85a06008ac744f01699276'
            '638bde31fd91f34c3c62f745ebfb38988f221d31c5d1eb345d2cb61c73e8a69e844239ab51760e5b44e9992d1b05786fea5549ed1442eb3dd5839fa176110817'
            'ed38acaef0e4a4341712d1a34d67cc5065920fcc808782b432a2cecc59b41192f25fb1c83e916c0407a18d5cd5eb5f04ffe74a665fc229eabfc1be4ab0ebb566'
            'd7b9f3bd752131ef42b00d3e1d6e579d923444613929fc3c3d18f5c8b9b9575b339e69ab5ca3698f7d1c29d41ba87461dfabf6c31abbc6d0789383e051c57ca3'
            'f8a7c94f17ee08b67cbd6cc84542d807b779087bc2657eef15940d8031d5aaf5c2cc2c6d8d824ce7296a576d6b470fc5d63ff365e104c92d5c1130f81d0a4c3a'
            '23bb106f505e7437d9e8a4419fb4c22244e9f308e5f853bd9b3b69c6ebd8b6ff793a3ada630bc2cf6e5ae103345115a716cfba41beed5f43be6e92f673281092'
            '78cf3c9c2fe1629b0113aa875216d0f488c384ae9dbe0962cc84cbc6639a6284ea3a1f884d7ba1fff646bda7e6927e54597221c0c4a06d34a79962630d8a017f'
            '07bb652e5dd086d543b3e1a150f1722bb8c1472a7d6cbcc1d1a8e2928db6750d6c41b68d333765fb6e1e42329bd330fa2ced760245a6904e16dd97cf53bb6a31'
            '875c3ce01d9c6d1b412f36166d2b1fcb94914904b2b1a788b8b34ee27e5814c31d4f97c39722bb0eefcaf738fd92d44d6c302c631c022a20fee9fbb73799e162'
            'cabf3ded10fb0c546abb9c6ef8ed80f095f424d33344e4b00fb17c44a829aaa7b512416b697ed5772ffafb25f35b47a58b8e30409e9cc6c0a7a188eb9621c6a3'
            'a351aa0aae0e24a1a6560f8c72f384556214795c55ec0e000c70cc2cfb795081c1e529fae8c69a6eae5271f9bae2e236285c9d3ed32ca3335912fd246170242c'
            'e0dd8640f80d3db689a523f9014bac3034191ee44b4e3d515dbac6bc496a39acb398a5cfca19c9c3f0226321e7f177cb268a0fca5ee5765ed924682c43fe5d27'
            'bc2e7dd15076e919a111a2480b6717a4ed3aef3094d1b097159aab90599553ab482bd07c1e9752a74e15544f352892b13d42718023a63585dd036ed484a2e054'
            '71b422bfe4f1ac3352461a9cdf5ba7f058b1c1b0c055d40f9940c54b7ffce7f1f3d6ad020874d37532a6b8a4ac3fd23182a434627666b6482221d3420b4701ef'
            '0c32f0282df882367772461720f2e87120ae5cb96dca06f006fb807005cf125f61196546c1a35e1f4f88ff88def23e31441aebeb9c23f55ee22c268dd3f0ef84'
            'fb17429635c8c633f3f9f301401a927d1c90723da6c73e500fe5bfd62328c78d12ea0fe9d4ca6b280325a83f16b778b3db44465784c39b864917e56dbf827d78'
            'abba7a482b53308ebd5fd4f05aab230e33dbaeaa11e7df43d41cffc00f71a921fd12be88bba311e50d6a92e32dc0ba2005f5336e8009b6a4ab68aad1653aca25'
            'fbd824fd62cd31f407a6182c991b7f23c418e6c4690382f6dec78dbf1e3d8ae12e56cb0397777046540efe2359995a20e7ff97d3f12fe35f332f673ce03cf7f6'
            '5763504bc61dc038ca965dcd80bc6e19506f1d9d9721f29f527ea1752a2c833229a61787c75d9f91ddc6957d91044871b4b23240675ebde75926a2243ef57288'
            '74ff25db1bf5a989000d19eeaa128b6b39d6d7ca66cb071fba5f06b952e6d760fb07cda6314c2246924c562484f6b5b37bf0a9cbf4ec84761b5957517231dd10'
            '22fa3b193d7887bf43a82fb31feacadb7ac2ebf979dca00c75584a2268e58bcdee58244c856a8ea61cac98e60c2021cd3bdd0cc0b595580b092b4489a4c33104'
            '639224ffce0088bf8a72aadd246ccd26915f6e88df4bb5eb7218782218c37481b2a3426386a2fd36957318c10ef133efde52807c7ad6557185db308d4d582883'
            '363f35f4ed01e0c5c2e5a83c05fa42cc39551060b83e9b2857f4af1de656a0b6fd36d0399de6e19dbe574244603f4faf4229b7447323e7af6062f73c7bd8a769'
            'c4d7fe90a9f061ab7c4e8ac4bf1604d2660a507ac24233cacc97e4fa57c004bee9b3fd21045e48edf1676f009c6d885dbf3a51774456f90022f276511cb17508'
            '2761b7fd9a1d256a04f83e5dd3777c29983e6f76900a5f4c88740e5acd79eb035cc12ab7f49a1ded5a440b571a0214f0bda1a6fc99bce5d5a2d593154a39b654'
            'a3904e540211440df3e932d502757885830af11f99872add3dde27f78f8b7cda32efc5f415d1748a9be2a69fd10b1ba36fa880f8ad633bfe4ef4781ea095877e')

prepare() {
  sh cuda_${pkgver}_${_driverver}_linux.run --target "${srcdir}" --noexec

  # Fix up samples tht use findgllib_mk
  for f in builds/cuda_samples/*/*/findgllib.mk; do
    patch $f cuda-findgllib_mk.diff
  done
}

package() {
  cd "${srcdir}/builds"

  rm -r NVIDIA*.run bin
  mkdir -p "${pkgdir}/opt/cuda/extras"
  mv cuda_samples "${pkgdir}/opt/cuda/samples"
  mv integration nsight_compute nsight_systems EULA.txt "${pkgdir}/opt/cuda"
  mv cuda_sanitizer_api/Sanitizer "${pkgdir}/opt/cuda/extras/Sanitizer"
  rmdir cuda_sanitizer_api
  for lib in *; do
    cp -r $lib/* "${pkgdir}/opt/cuda/"
  done

  # Define compilers for CUDA to use.
  # This allows us to use older versions of GCC if we have to.
  ln -s /usr/bin/gcc-9 "${pkgdir}/opt/cuda/bin/gcc"
  ln -s /usr/bin/g++-9 "${pkgdir}/opt/cuda/bin/g++"

  # Install profile and ld.so.config files
  install -Dm755 "${srcdir}/cuda.sh" "${pkgdir}/etc/profile.d/cuda.sh"
  install -Dm644 "${srcdir}/cuda.conf" "${pkgdir}/etc/ld.so.conf.d/cuda.conf"

  # Install pkgconfig files
  mkdir -p "$pkgdir"/usr/lib/pkgconfig
  cp "${srcdir}"/*.pc "${pkgdir}"/usr/lib/pkgconfig

  mkdir -p "${pkgdir}/usr/share/licenses/${pkgname}"
  ln -s /opt/cuda/doc/pdf/EULA.pdf "${pkgdir}/usr/share/licenses/${pkgname}/EULA.pdf"

  # Allow newer compilers to work. This is not officially supported in the Arch package but
  # if users want to try, let them try.
  # See https://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html#system-requirements
  # for official requirements
  sed -i "/.*unsupported GNU version.*/d" "${pkgdir}"/opt/cuda/targets/x86_64-linux/include/crt/host_config.h
  sed -i "/.*unsupported clang version.*/d" "${pkgdir}"/opt/cuda/targets/x86_64-linux/include/crt/host_config.h

  # Fix Makefile paths to CUDA
  for f in $(find "$pkgdir"/opt/cuda -name Makefile); do
    sed -i "s|/usr/local/cuda|/opt/cuda|g" "$f"
  done
}

# vim:set ts=2 sw=2 et:

